#pragma once

#include "dynamixel.h"
#include "ProtocolBase.h"

#include <cassert>
#include <chrono>
#include <cstring>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <string>

#include "Layout.h"

#include <iostream>

namespace dynamixel {

struct USB2Dynamixel {
	using Timeout = std::chrono::microseconds;

	USB2Dynamixel(int baudrate, std::vector<std::string> const& deviceNames);
	~USB2Dynamixel();

	[[nodiscard]] bool ping(MotorID motor, Timeout timeout) const;
	[[nodiscard]] auto read(MotorID motor, int baseRegister, uint8_t length, Timeout timeout) const -> std::tuple<bool, MotorID, ErrorCode, Parameter>;
	[[nodiscard]] auto bulk_read(std::vector<std::tuple<MotorID, int, uint8_t>> const& motors, Timeout timeout) const -> std::vector<std::tuple<MotorID, int, ErrorCode, Parameter>>;

	void write(MotorID motor, Parameter const& txBuf) const;
	void sync_write(std::map<MotorID, Parameter> const& motorParams, int baseRegister) const;

	void reset(MotorID motor) const;
	void reboot(MotorID motor)const;

private:
	std::unique_ptr<ProtocolBase> m_pimpl;
	mutable std::mutex mMutex;
};

template <auto baseRegister, size_t length>
[[nodiscard]] auto read(USB2Dynamixel const& dyn, MotorID motor, USB2Dynamixel::Timeout timeout) -> std::tuple<bool, MotorID, ErrorCode, Layout<baseRegister, size_t(length)>> {
	using RType = Layout<baseRegister, length>;
	static_assert(length == sizeof(RType));

	auto [timeoutFlag, motorID, errorCode, rxBuf] = dyn.read(motor, int(baseRegister), length, timeout);
	if (timeoutFlag) {
		return std::make_tuple(true, MotorIDInvalid, errorCode, RType{});
	} else if (motorID == MotorIDInvalid) {
		return std::make_tuple(false, MotorIDInvalid, errorCode, RType{});
	}
	return std::make_tuple(false, motorID, errorCode, RType(rxBuf));
}


template <auto baseRegister, size_t length, typename ...Extras>
[[nodiscard]] auto bulk_read(USB2Dynamixel const& dyn, std::vector<std::tuple<MotorID, Extras...>> const& motors, USB2Dynamixel::Timeout timeout) -> std::vector<std::tuple<MotorID, Extras..., ErrorCode, Layout<baseRegister, length>>> {
	if (motors.empty()) return {};

	std::vector<std::tuple<MotorID, int, uint8_t>> request;
	for (auto data : motors) {
		auto id = std::get<0>(data);
		request.push_back(std::make_tuple(id, int(baseRegister), uint8_t(length)));
	}
	auto list = dyn.bulk_read(request, timeout);

	std::vector<std::tuple<MotorID, Extras..., ErrorCode, Layout<baseRegister, length>>> response;
	auto iter = begin(motors);
	for (auto const& [id, _reg, errorCode, params] : list) {
		response.push_back(std::tuple_cat(*iter, std::make_tuple(errorCode, Layout<baseRegister, length>{params})));
		++iter;
	}
	return response;
}

template <auto baseRegister, size_t length>
void write(USB2Dynamixel const& dyn, MotorID motor, Layout<baseRegister, length> layout) {
	std::vector<std::byte> txBuf(sizeof(layout)+1);
	txBuf[0] = std::byte(baseRegister);
	memcpy(txBuf.data()+1, &layout, sizeof(layout));
	dyn.write(motor, txBuf);
}


template <template<auto, size_t> class Layout, auto baseRegister, size_t Length>
void sync_write(USB2Dynamixel const& dyn, std::map<MotorID, Layout<baseRegister, Length>> const& params) {
	if (params.empty()) return;

	std::map<MotorID, Parameter> motorParams;
	for (auto const& [id, layout] : params) {
		auto& buffer = motorParams[id];
		buffer.resize(Length);
		memcpy(buffer.data(), &layout, Length);
	}
	dyn.sync_write(motorParams, int(baseRegister));
}

template <typename Layout, typename ...Extras>
void sync_sync_write(USB2Dynamixel const& dyn, std::vector<std::tuple<MotorID, Extras...>> const& motors, Layout const& layout) {
	if (motors.empty()) return;

	std::map<MotorID, Layout> motorParams;
	for (auto m : motors) {
		motorParams[std::get<0>(m)] = layout;
	}
	sync_write(dyn, motorParams);
}


}
