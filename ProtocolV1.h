#pragma once

#include "ProtocolBase.h"

#include <chrono>
#include <cstring>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <simplyfile/SerialPort.h>



namespace dynamixel {

struct ProtocolV1 : public ProtocolBase {

	simplyfile::SerialPort mPort;

	std::chrono::high_resolution_clock::time_point now() const {
		return std::chrono::high_resolution_clock::now();
	}

	ProtocolV1(simplyfile::SerialPort _port)
		: mPort {std::move(_port)}
	{}

	void writePacket(MotorID motorID, Instruction instr, Parameter data) const {
		uint8_t length = 2 + data.size();

		Parameter txBuf {
			std::byte{0xff}, std::byte{0xff}, std::byte{motorID}, std::byte{length}, std::byte(instr)
		};
		txBuf.insert(txBuf.end(), data.begin(), data.end());

		txBuf.push_back(calculateChecksum(txBuf));
		write(mPort, txBuf);
	}

	/** tries to read up to incomingLength bytes from filedescriptor
	 *
	 * return value
	 *  [timeoutFlag, valid, parameters] = readPacket(...);
	 *
	 *  timeoutFlag indicates if a timeout has occurred
	 *  valid       inidcates if parameters form a valid packet
	 *  paremeters  is a vector with read bytes
	 */
	auto readPacket(uint8_t incomingLength, Timeout timeout) const -> std::tuple<bool, bool, Parameter> override {
		auto startTime = now();

		Parameter rxBuf;
		rxBuf.reserve(incomingLength);

		bool timeoutFlag = false;
		while (rxBuf.size() < incomingLength and not timeoutFlag) {
			auto buffer = read(mPort, incomingLength - rxBuf.size());
			rxBuf.insert(rxBuf.end(), buffer.begin(), buffer.end());
			timeoutFlag = (timeout.count() != 0) and (now() - startTime >= timeout);
		};
		bool valid = rxBuf.size() == incomingLength and validatePacket(rxBuf);

		if (not valid) {
			flushRead(mPort);
			rxBuf = {};
		} else {
			rxBuf = {std::next(begin(rxBuf), 5), std::next(begin(rxBuf), rxBuf.size()-1)};
		}

		return std::make_tuple(timeoutFlag, valid, std::move(rxBuf));
	}

	bool validatePacket(Parameter const& rxBuf) const {
		bool success = 0xff == uint8_t(rxBuf[0]);
		success &= 0xff == uint8_t(rxBuf[1]);
		success &= 0xff != uint8_t(rxBuf[2]);
		success &= (rxBuf.size() - 4) == uint8_t(rxBuf[3]);
		uint8_t checkSum = 0;
		for (size_t i(2); i < rxBuf.size(); ++i) {
			checkSum += uint8_t(rxBuf[i]);
		}
		success &= 0xff == uint8_t(checkSum);
		return success;
	}

	[[nodiscard]]
	std::byte calculateChecksum(Parameter const& packet) const {
		uint32_t checkSum = 0;
		for (size_t i(2); i < packet.size(); ++i) {
			checkSum += uint8_t(packet[i]);
		}
		return std::byte(~checkSum);
	}

};

}