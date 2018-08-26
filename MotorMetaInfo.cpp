#include "MotorMetaInfo.h"

namespace dynamixel {

auto getMotorDataBase() -> std::map<int, MotorData> const& {
	using A = RegisterData::Access;
	static std::map<int, MotorData> data {
		{1020, MotorData {
			"XM430-W350",
			{"XM430-W350-T", "XM430-W350-R"},
			{
				{   0, RegisterData{  0, 2, true,  A:: R,  1020, "Model Number", "Model Number"}},
				{   2, RegisterData{  2, 4, true,  A:: R,    {}, "Model Information", "Model Information"}},
				{   6, RegisterData{  6, 1, true,  A:: R,    {}, "Version of Firmware", "Firmware Version"}},
				{   7, RegisterData{  7, 1, true,  A::RW,     1, "ID", "Dynamixel ID"}},
				{   8, RegisterData{  8, 1, true,  A::RW,     1, "Baud Rate", "Communication Baud Rate"}},
				{   9, RegisterData{  9, 1, true,  A::RW,   250, "Return Delay Time", "Response Delay Time"}},
				{  10, RegisterData{ 10, 1, true,  A::RW,     0, "Drive Mode", "Drive Mode"}},
				{  11, RegisterData{ 11, 1, true,  A::RW,     3, "Operating Mode", "Operating Mode"}},
				{  12, RegisterData{ 12, 1, true,  A::RW,   255, "Secondary(Shadow) ID", "Secondary(Shadow) ID"}},
				{  13, RegisterData{ 13, 1, true,  A::RW,     2, "Protocol Version", "Protocol Version"}},
				{  20, RegisterData{ 20, 4, true,  A::RW,     0, "Homing Offset", "Home Position Offset"}},
				{  24, RegisterData{ 24, 4, true,  A::RW,    10, "Moving Threshold", "Velocity Threshold for Movement Detection"}},
				{  31, RegisterData{ 31, 1, true,  A::RW,    80, "Temperature Limit", "Maximum Internal Temperature Limit"}},
				{  32, RegisterData{ 32, 2, true,  A::RW,   160, "Max Voltage Limit", "Maximum Voltage Limit"}},
				{  34, RegisterData{ 34, 2, true,  A::RW,    95, "Min Voltage Limit", "Minimum Voltage Limit"}},
				{  36, RegisterData{ 36, 2, true,  A::RW,   885, "PWM Limit", "Maximum PWM Limit"}},
				{  38, RegisterData{ 38, 2, true,  A::RW,  1193, "Current Limit", "Maximum Current Limit"}},
				{  40, RegisterData{ 40, 4, true,  A::RW, 32767, "Acceleration Limit", "Maximum Acceleration Limit"}},
				{  44, RegisterData{ 44, 4, true,  A::RW,   350, "Velocity Limit", "Maximum Velocity Limit"}},
				{  48, RegisterData{ 48, 4, true,  A::RW,  4095, "Max Position Limit", "Maximum Position Limit"}},
				{  52, RegisterData{ 52, 4, true,  A::RW,     0, "Min Position Limit", "Minimum Position Limit"}},
				{  63, RegisterData{ 63, 1, true,  A::RW,    52, "Shutdown", "Shutdown Dynamixel"}},
				{  64, RegisterData{ 64, 1, false, A::RW,     0, "Torque Enable", "Motor Torque On/Off"}},
				{  65, RegisterData{ 65, 1, false, A::RW,     0, "LED", "Status LED On/Off"}},
				{  68, RegisterData{ 68, 1, false, A::RW,     2, "Status Return Level", "Select Types of Status Return"}},
				{  69, RegisterData{ 69, 1, false, A:: R,     0, "Registered Instruction", "Check Reception of Instruction"}},
				{  70, RegisterData{ 70, 1, false, A:: R,     0, "Hardware Error Status", "Hardware Error Status"}},
				{  76, RegisterData{ 76, 2, false, A::RW,  1920, "Velocity I Gain", "I Gain of Velocity"}},
				{  78, RegisterData{ 78, 2, false, A::RW,   100, "Velocity P Gain", "P Gain of Velocity"}},
				{  80, RegisterData{ 80, 2, false, A::RW,     0, "Position D Gain", "D Gain of Position"}},
				{  82, RegisterData{ 82, 2, false, A::RW,     0, "Position I Gain", "I Gain of Position"}},
				{  84, RegisterData{ 84, 2, false, A::RW,   800, "Position P Gain", "P Gain of Position"}},
				{  88, RegisterData{ 88, 2, false, A::RW,     0, "Feedforward 2nd Gain", "2nd Gain of Feed-Forward"}},
				{  90, RegisterData{ 90, 2, false, A::RW,     0, "Feedforward 1st Gain", "1st Gain of Feed-Forward"}},
				{  98, RegisterData{ 98, 1, false, A::RW,     0, "Bus Watchdog", "Dynamixel Bus Watchdog"}},
				{ 100, RegisterData{100, 2, false, A::RW,    {}, "Goal PWM", "Target PWM Value"}},
				{ 102, RegisterData{102, 2, false, A::RW,    {}, "Goal Current", "Target Current Value"}},
				{ 104, RegisterData{104, 4, false, A::RW,    {}, "Goal Velocity", "Target Velocity Value"}},
				{ 108, RegisterData{108, 4, false, A::RW,     0, "Profile Acceleration", "Acceleration Value of Profile"}},
				{ 112, RegisterData{112, 4, false, A::RW,     0, "Profile Velocity", "Velocity Value of Profile"}},
				{ 116, RegisterData{116, 4, false, A::RW,    {}, "Goal Position", "Target Position Value"}},
				{ 120, RegisterData{120, 2, false, A:: R,    {}, "Realtime Tick", "Count Time in millisecond"}},
				{ 122, RegisterData{122, 1, false, A:: R,     0, "Moving", "Movement Status"}},
				{ 123, RegisterData{123, 1, false, A:: R,     0, "Moving Status", "Detailed Information of Movement Status"}},
				{ 124, RegisterData{124, 2, false, A:: R,    {}, "Present PWM", "Current PWM Value"}},
				{ 126, RegisterData{126, 2, false, A:: R,    {}, "Present Current", "Current Current Value"}},
				{ 128, RegisterData{128, 4, false, A:: R,    {}, "Present Velocity", "Current Velocity Value"}},
				{ 132, RegisterData{132, 4, false, A:: R,    {}, "Present Position", "Current Position Value"}},
				{ 136, RegisterData{136, 4, false, A:: R,    {}, "Velocity Trajectory", "Target Velocity Trajectory Generated by Profile"}},
				{ 140, RegisterData{140, 4, false, A:: R,    {}, "Position Trajectory", "Target Position Trajectory Generated by Profile"}},
				{ 144, RegisterData{144, 2, false, A:: R,    {}, "Present Input Voltage", "Current Input Voltage"}},
				{ 146, RegisterData{146, 1, false, A:: R,    {}, "Present Temperature", "Current Internal Temperature"}}
			}
		}},
		{ 29, MotorData {
			"MX28",
			{"MX-28T", "MX-28R", "MX-28AT", "MX-28AR"},
			{
				{  0, RegisterData{  0, 2,  true, A:: R,     29, "Model Number", "model number"}},
				{  2, RegisterData{  2, 1,  true, A:: R,     {}, "Version of Firmware", "Information on the version of firmware"}},
				{  3, RegisterData{  3, 1,  true, A::RW,      1, "ID", "ID of Dynamixel"}},
				{  4, RegisterData{  4, 1,  true, A::RW,     34, "Baud Rate", "Baud Rate of Dynamixel"}},
				{  5, RegisterData{  5, 1,  true, A::RW,    250, "Return Delay Time", "Return Delay Time"}},
				{  6, RegisterData{  6, 2,  true, A::RW,      0, "CW Angle Limit", "clockwise Angle Limit"}},
				{  8, RegisterData{  8, 2,  true, A::RW, 0x0fff, "CCW Angle Limit", "counterclockwise Angle Limit"}},
				{ 11, RegisterData{ 11, 1,  true, A::RW,     80, "Highest Limit Temperature", "Internal Limit Temperature"}},
				{ 12, RegisterData{ 12, 1,  true, A::RW,     60, "Lowest Limit Voltage", "Lowest Limit Voltage"}},
				{ 13, RegisterData{ 13, 1,  true, A::RW,    160, "Highest Limit Voltage", "Highest Limit Voltage"}},
				{ 14, RegisterData{ 14, 2,  true, A::RW, 0x03ff, "Max Torque", "Max. Torque"}},
				{ 16, RegisterData{ 16, 1,  true, A::RW,      2, "Status Return Level", "Status Return Level"}},
				{ 17, RegisterData{ 17, 1,  true, A::RW,     36, "Alarm LED", "LED for Alarm"}},
				{ 18, RegisterData{ 18, 1,  true, A::RW,     36, "Alarm Shutdown", "Shutdown for Alarm"}},
				{ 20, RegisterData{ 20, 2,  true, A::RW,      0, "Multi Turn Offset", "multi{}turn offset"}},
				{ 22, RegisterData{ 22, 1,  true, A::RW,      1, "Resolution Divider", "Resolution divider"}},
				{ 24, RegisterData{ 24, 1, false, A::RW,      0, "Torque Enable", "Torque On/Off"}},
				{ 25, RegisterData{ 25, 1, false, A::RW,      0, "LED", "LED On/Off"}},
				{ 26, RegisterData{ 26, 1, false, A::RW,      0, "D Gain", "Derivative Gain"}},
				{ 27, RegisterData{ 27, 1, false, A::RW,      0, "I Gain", "Integral Gain"}},
				{ 28, RegisterData{ 28, 1, false, A::RW,     32, "P Gain", "Proportional Gain"}},
				{ 30, RegisterData{ 30, 2, false, A::RW,     {}, "Goal Position", "Goal Position"}},
				{ 32, RegisterData{ 32, 2, false, A::RW,     {}, "Moving Speed", "Moving Speed (Moving Velocity)"}},
				{ 34, RegisterData{ 34, 2, false, A::RW,     {}, "Torque Limit", "Torque Limit (Goal Torque)"}},
				{ 36, RegisterData{ 36, 2, false, A:: R,     {}, "Present Position", "Current Position (Present Velocity)"}},
				{ 38, RegisterData{ 38, 2, false, A:: R,     {}, "Present Speed", "Current Speed"}},
				{ 40, RegisterData{ 40, 2, false, A:: R,     {}, "Present Load", "Current Load"}},
				{ 42, RegisterData{ 42, 1, false, A:: R,     {}, "Present Voltage", "Current Voltage"}},
				{ 43, RegisterData{ 43, 1, false, A:: R,     {}, "Present Temperature", "Current Temperature"}},
				{ 44, RegisterData{ 44, 1, false, A:: R,      0, "Registered", "Means if Instruction is registered"}},
				{ 46, RegisterData{ 46, 1, false, A:: R,      0, "Moving", "Means if there is any movement"}},
				{ 47, RegisterData{ 47, 1, false, A::RW,      0, "Lock", "Locking EEPROM"}},
				{ 48, RegisterData{ 48, 2, false, A::RW,      0, "Punch", "Punch"}},
				{ 68, RegisterData{ 68, 2, false, A::RW,      0, "Current", "Consuming Current"}},
				{ 70, RegisterData{ 70, 1, false, A::RW,      0, "Torque Control Mode Enable", "Torque control mode on/off"}},
				{ 71, RegisterData{ 71, 2, false, A::RW,      0, "Goal Torque", "goal torque value"}},
				{ 73, RegisterData{ 73, 1, false, A::RW,      0, "Goal Acceleration", "Goal Acceleration"}},
			}
		}},
		{310, MotorData {
			"MX64",
			{"MX-64T", "MX-64R", "MX-64AT", "MX-64AR"},
			{
				{  0, RegisterData{  0, 2,  true, A:: R,    310, "Model Number", "model number"}},
				{  2, RegisterData{  2, 1,  true, A:: R,     {}, "Version of Firmware", "Information on the version of firmware"}},
				{  3, RegisterData{  3, 1,  true, A::RW,      1, "ID", "ID of Dynamixel"}},
				{  4, RegisterData{  4, 1,  true, A::RW,     34, "Baud Rate", "Baud Rate of Dynamixel"}},
				{  5, RegisterData{  5, 1,  true, A::RW,    250, "Return Delay Time", "Return Delay Time"}},
				{  6, RegisterData{  6, 2,  true, A::RW,      0, "CW Angle Limit", "clockwise Angle Limit"}},
				{  8, RegisterData{  8, 2,  true, A::RW, 0x0fff, "CCW Angle Limit", "counterclockwise Angle Limit"}},
				{ 11, RegisterData{ 11, 1,  true, A::RW,     80, "Highest Limit Temperature", "Internal Limit Temperature"}},
				{ 12, RegisterData{ 12, 1,  true, A::RW,     60, "Lowest Limit Voltage", "Lowest Limit Voltage"}},
				{ 13, RegisterData{ 13, 1,  true, A::RW,    160, "Highest Limit Voltage", "Highest Limit Voltage"}},
				{ 14, RegisterData{ 14, 2,  true, A::RW, 0x03ff, "Max Torque", "Max. Torque"}},
				{ 16, RegisterData{ 16, 1,  true, A::RW,      2, "Status Return Level", "Status Return Level"}},
				{ 17, RegisterData{ 17, 1,  true, A::RW,     36, "Alarm LED", "LED for Alarm"}},
				{ 18, RegisterData{ 18, 1,  true, A::RW,     36, "Alarm Shutdown", "Shutdown for Alarm"}},
				{ 20, RegisterData{ 20, 2,  true, A::RW,      0, "Multi Turn Offset", "multi{}turn offset"}},
				{ 22, RegisterData{ 22, 1,  true, A::RW,      1, "Resolution Divider", "Resolution divider"}},
				{ 24, RegisterData{ 24, 1, false, A::RW,      0, "Torque Enable", "Torque On/Off"}},
				{ 25, RegisterData{ 25, 1, false, A::RW,      0, "LED", "LED On/Off"}},
				{ 26, RegisterData{ 26, 1, false, A::RW,      0, "D Gain", "Derivative Gain"}},
				{ 27, RegisterData{ 27, 1, false, A::RW,      0, "I Gain", "Integral Gain"}},
				{ 28, RegisterData{ 28, 1, false, A::RW,     32, "P Gain", "Proportional Gain"}},
				{ 30, RegisterData{ 30, 2, false, A::RW,     {}, "Goal Position", "Goal Position"}},
				{ 32, RegisterData{ 32, 2, false, A::RW,     {}, "Moving Speed", "Moving Speed (Moving Velocity)"}},
				{ 34, RegisterData{ 34, 2, false, A::RW,     {}, "Torque Limit", "Torque Limit (Goal Torque)"}},
				{ 36, RegisterData{ 36, 2, false, A:: R,     {}, "Present Position", "Current Position (Present Velocity)"}},
				{ 38, RegisterData{ 38, 2, false, A:: R,     {}, "Present Speed", "Current Speed"}},
				{ 40, RegisterData{ 40, 2, false, A:: R,     {}, "Present Load", "Current Load"}},
				{ 42, RegisterData{ 42, 1, false, A:: R,     {}, "Present Voltage", "Current Voltage"}},
				{ 43, RegisterData{ 43, 1, false, A:: R,     {}, "Present Temperature", "Current Temperature"}},
				{ 44, RegisterData{ 44, 1, false, A:: R,      0, "Registered", "Means if Instruction is registered"}},
				{ 46, RegisterData{ 46, 1, false, A:: R,      0, "Moving", "Means if there is any movement"}},
				{ 47, RegisterData{ 47, 1, false, A::RW,      0, "Lock", "Locking EEPROM"}},
				{ 48, RegisterData{ 48, 2, false, A::RW,      0, "Punch", "Punch"}},
				{ 68, RegisterData{ 68, 2, false, A::RW,      0, "Current", "Consuming Current"}},
				{ 70, RegisterData{ 70, 1, false, A::RW,      0, "Torque Control Mode Enable", "Torque control mode on/off"}},
				{ 71, RegisterData{ 71, 2, false, A::RW,      0, "Goal Torque", "goal torque value"}},
				{ 73, RegisterData{ 73, 1, false, A::RW,      0, "Goal Acceleration", "Goal Acceleration"}},
			}
		}},
		{320, MotorData {
			"MX106",
			{"MX-106T", "MX-106R"},
			{
				{  0, RegisterData{  0, 2,  true, A:: R,    320, "Model Number", "model number"}},
				{  2, RegisterData{  2, 1,  true, A:: R,     {}, "Version of Firmware", "Information on the version of firmware"}},
				{  3, RegisterData{  3, 1,  true, A::RW,      1, "ID", "ID of Dynamixel"}},
				{  4, RegisterData{  4, 1,  true, A::RW,     34, "Baud Rate", "Baud Rate of Dynamixel"}},
				{  5, RegisterData{  5, 1,  true, A::RW,    250, "Return Delay Time", "Return Delay Time"}},
				{  6, RegisterData{  6, 2,  true, A::RW,      0, "CW Angle Limit", "clockwise Angle Limit"}},
				{  8, RegisterData{  8, 2,  true, A::RW, 0x0fff, "CCW Angle Limit", "counterclockwise Angle Limit"}},
				{ 10, RegisterData{ 10, 1,  true, A::RW,      0, "Drive Mode", "Dual Mode Setting"}},
				{ 11, RegisterData{ 11, 1,  true, A::RW,     80, "Highest Limit Temperature", "Internal Limit Temperature"}},
				{ 12, RegisterData{ 12, 1,  true, A::RW,     60, "Lowest Limit Voltage", "Lowest Limit Voltage"}},
				{ 13, RegisterData{ 13, 1,  true, A::RW,    160, "Highest Limit Voltage", "Highest Limit Voltage"}},
				{ 14, RegisterData{ 14, 2,  true, A::RW, 0x03ff, "Max Torque", "Max. Torque"}},
				{ 16, RegisterData{ 16, 1,  true, A::RW,      2, "Status Return Level", "Status Return Level"}},
				{ 17, RegisterData{ 17, 1,  true, A::RW,     36, "Alarm LED", "LED for Alarm"}},
				{ 18, RegisterData{ 18, 1,  true, A::RW,     36, "Alarm Shutdown", "Shutdown for Alarm"}},
				{ 20, RegisterData{ 20, 2,  true, A::RW,      0, "Multi Turn Offset", "multi{}turn offset"}},
				{ 22, RegisterData{ 22, 1,  true, A::RW,      1, "Resolution Divider", "Resolution divider"}},
				{ 24, RegisterData{ 24, 1, false, A::RW,      0, "Torque Enable", "Torque On/Off"}},
				{ 25, RegisterData{ 25, 1, false, A::RW,      0, "LED", "LED On/Off"}},
				{ 26, RegisterData{ 26, 1, false, A::RW,      0, "D Gain", "Derivative Gain"}},
				{ 27, RegisterData{ 27, 1, false, A::RW,      0, "I Gain", "Integral Gain"}},
				{ 28, RegisterData{ 28, 1, false, A::RW,     32, "P Gain", "Proportional Gain"}},
				{ 30, RegisterData{ 30, 2, false, A::RW,     {}, "Goal Position", "Goal Position"}},
				{ 32, RegisterData{ 32, 2, false, A::RW,     {}, "Moving Speed", "Moving Speed (Moving Velocity)"}},
				{ 34, RegisterData{ 34, 2, false, A::RW,     {}, "Torque Limit", "Torque Limit (Goal Torque)"}},
				{ 36, RegisterData{ 36, 2, false, A:: R,     {}, "Present Position", "Current Position (Present Velocity)"}},
				{ 38, RegisterData{ 38, 2, false, A:: R,     {}, "Present Speed", "Current Speed"}},
				{ 40, RegisterData{ 40, 2, false, A:: R,     {}, "Present Load", "Current Load"}},
				{ 42, RegisterData{ 42, 1, false, A:: R,     {}, "Present Voltage", "Current Voltage"}},
				{ 43, RegisterData{ 43, 1, false, A:: R,     {}, "Present Temperature", "Current Temperature"}},
				{ 44, RegisterData{ 44, 1, false, A:: R,      0, "Registered", "Means if Instruction is registered"}},
				{ 46, RegisterData{ 46, 1, false, A:: R,      0, "Moving", "Means if there is any movement"}},
				{ 47, RegisterData{ 47, 1, false, A::RW,      0, "Lock", "Locking EEPROM"}},
				{ 48, RegisterData{ 48, 2, false, A::RW,      0, "Punch", "Punch"}},
				{ 68, RegisterData{ 68, 2, false, A::RW,      0, "Current", "Consuming Current"}},
				{ 70, RegisterData{ 70, 1, false, A::RW,      0, "Torque Control Mode Enable", "Torque control mode on/off"}},
				{ 71, RegisterData{ 71, 2, false, A::RW,      0, "Goal Torque", "goal torque value"}},
				{ 73, RegisterData{ 73, 1, false, A::RW,      0, "Goal Acceleration", "Goal Acceleration"}},
			}
		}},
		{30, MotorData {
			"MX28-V2",
			{"MX-28T-V2", "MX-28R-V2", "MX-28AT-V2", "MX-28AR-V2"},
			{
				{   0, RegisterData{  0, 2, true,  A:: R,    30, "Model Number", "Model Number"}},
				{   2, RegisterData{  2, 4, true,  A:: R,    {}, "Model Information", "Model Information"}},
				{   6, RegisterData{  6, 1, true,  A:: R,    {}, "Version of Firmware", "Firmware Version"}},
				{   7, RegisterData{  7, 1, true,  A::RW,     1, "ID", "Dynamixel ID"}},
				{   8, RegisterData{  8, 1, true,  A::RW,     1, "Baud Rate", "Communication Baud Rate"}},
				{   9, RegisterData{  9, 1, true,  A::RW,   250, "Return Delay Time", "Response Delay Time"}},
				{  10, RegisterData{ 10, 1, true,  A::RW,     0, "Drive Mode", "Drive Mode"}},
				{  11, RegisterData{ 11, 1, true,  A::RW,     3, "Operating Mode", "Operating Mode"}},
				{  12, RegisterData{ 12, 1, true,  A::RW,   255, "Secondary(Shadow) ID", "Secondary(Shadow) ID"}},
				{  13, RegisterData{ 13, 1, true,  A::RW,     2, "Protocol Version", "Protocol Version"}},
				{  20, RegisterData{ 20, 4, true,  A::RW,     0, "Homing Offset", "Home Position Offset"}},
				{  24, RegisterData{ 24, 4, true,  A::RW,    10, "Moving Threshold", "Velocity Threshold for Movement Detection"}},
				{  31, RegisterData{ 31, 1, true,  A::RW,    80, "Temperature Limit", "Maximum Internal Temperature Limit"}},
				{  32, RegisterData{ 32, 2, true,  A::RW,   160, "Max Voltage Limit", "Maximum Voltage Limit"}},
				{  34, RegisterData{ 34, 2, true,  A::RW,    95, "Min Voltage Limit", "Minimum Voltage Limit"}},
				{  36, RegisterData{ 36, 2, true,  A::RW,   885, "PWM Limit", "Maximum PWM Limit"}},
				{  40, RegisterData{ 40, 4, true,  A::RW, 32767, "Acceleration Limit", "Maximum Acceleration Limit"}},
				{  44, RegisterData{ 44, 4, true,  A::RW,   380, "Velocity Limit", "Maximum Velocity Limit"}},
				{  48, RegisterData{ 48, 4, true,  A::RW,  4095, "Max Position Limit", "Maximum Position Limit"}},
				{  52, RegisterData{ 52, 4, true,  A::RW,     0, "Min Position Limit", "Minimum Position Limit"}},
				{  63, RegisterData{ 63, 1, true,  A::RW,    52, "Shutdown", "Shutdown Dynamixel"}},
				{  64, RegisterData{ 64, 1, false, A::RW,     0, "Torque Enable", "Motor Torque On/Off"}},
				{  65, RegisterData{ 65, 1, false, A::RW,     0, "LED", "Status LED On/Off"}},
				{  68, RegisterData{ 68, 1, false, A::RW,     2, "Status Return Level", "Select Types of Status Return"}},
				{  69, RegisterData{ 69, 1, false, A:: R,     0, "Registered Instruction", "Check Reception of Instruction"}},
				{  70, RegisterData{ 70, 1, false, A:: R,     0, "Hardware Error Status", "Hardware Error Status"}},
				{  76, RegisterData{ 76, 2, false, A::RW,  1920, "Velocity I Gain", "I Gain of Velocity"}},
				{  78, RegisterData{ 78, 2, false, A::RW,   100, "Velocity P Gain", "P Gain of Velocity"}},
				{  80, RegisterData{ 80, 2, false, A::RW,     0, "Position D Gain", "D Gain of Position"}},
				{  82, RegisterData{ 82, 2, false, A::RW,     0, "Position I Gain", "I Gain of Position"}},
				{  84, RegisterData{ 84, 2, false, A::RW,   850, "Position P Gain", "P Gain of Position"}},
				{  88, RegisterData{ 88, 2, false, A::RW,     0, "Feedforward 2nd Gain", "2nd Gain of Feed-Forward"}},
				{  90, RegisterData{ 90, 2, false, A::RW,     0, "Feedforward 1st Gain", "1st Gain of Feed-Forward"}},
				{  98, RegisterData{ 98, 1, false, A::RW,     0, "Bus Watchdog", "Dynamixel Bus Watchdog"}},
				{ 100, RegisterData{100, 2, false, A::RW,    {}, "Goal PWM", "Target PWM Value"}},
				{ 102, RegisterData{102, 2, false, A::RW,    {}, "Goal Current", "Target Current Value"}},
				{ 104, RegisterData{104, 4, false, A::RW,    {}, "Goal Velocity", "Target Velocity Value"}},
				{ 108, RegisterData{108, 4, false, A::RW,     0, "Profile Acceleration", "Acceleration Value of Profile"}},
				{ 112, RegisterData{112, 4, false, A::RW,     0, "Profile Velocity", "Velocity Value of Profile"}},
				{ 116, RegisterData{116, 4, false, A::RW,    {}, "Goal Position", "Target Position Value"}},
				{ 120, RegisterData{120, 2, false, A:: R,    {}, "Realtime Tick", "Count Time in millisecond"}},
				{ 122, RegisterData{122, 1, false, A:: R,     0, "Moving", "Movement Status"}},
				{ 123, RegisterData{123, 1, false, A:: R,     0, "Moving Status", "Detailed Information of Movement Status"}},
				{ 124, RegisterData{124, 2, false, A:: R,    {}, "Present PWM", "Current PWM Value"}},
				{ 126, RegisterData{126, 2, false, A:: R,    {}, "Present Current", "Current Current Value"}},
				{ 128, RegisterData{128, 4, false, A:: R,    {}, "Present Velocity", "Current Velocity Value"}},
				{ 132, RegisterData{132, 4, false, A:: R,    {}, "Present Position", "Current Position Value"}},
				{ 136, RegisterData{136, 4, false, A:: R,    {}, "Velocity Trajectory", "Target Velocity Trajectory Generated by Profile"}},
				{ 140, RegisterData{140, 4, false, A:: R,    {}, "Position Trajectory", "Target Position Trajectory Generated by Profile"}},
				{ 144, RegisterData{144, 2, false, A:: R,    {}, "Present Input Voltage", "Current Input Voltage"}},
				{ 146, RegisterData{146, 1, false, A:: R,    {}, "Present Temperature", "Current Internal Temperature"}}
			}
		}},
		{311, MotorData {
			"MX64-V2",
			{"MX-64T-V2", "MX-64R-V2", "MX-64AT-V2", "MX-64AR-V2"},
			{
				{   0, RegisterData{  0, 2, true,  A:: R,   311, "Model Number", "Model Number"}},
				{   2, RegisterData{  2, 4, true,  A:: R,    {}, "Model Information", "Model Information"}},
				{   6, RegisterData{  6, 1, true,  A:: R,    {}, "Version of Firmware", "Firmware Version"}},
				{   7, RegisterData{  7, 1, true,  A::RW,     1, "ID", "Dynamixel ID"}},
				{   8, RegisterData{  8, 1, true,  A::RW,     1, "Baud Rate", "Communication Baud Rate"}},
				{   9, RegisterData{  9, 1, true,  A::RW,   250, "Return Delay Time", "Response Delay Time"}},
				{  10, RegisterData{ 10, 1, true,  A::RW,     0, "Drive Mode", "Drive Mode"}},
				{  11, RegisterData{ 11, 1, true,  A::RW,     3, "Operating Mode", "Operating Mode"}},
				{  12, RegisterData{ 12, 1, true,  A::RW,   255, "Secondary(Shadow) ID", "Secondary(Shadow) ID"}},
				{  13, RegisterData{ 13, 1, true,  A::RW,     2, "Protocol Version", "Protocol Version"}},
				{  20, RegisterData{ 20, 4, true,  A::RW,     0, "Homing Offset", "Home Position Offset"}},
				{  24, RegisterData{ 24, 4, true,  A::RW,    10, "Moving Threshold", "Velocity Threshold for Movement Detection"}},
				{  31, RegisterData{ 31, 1, true,  A::RW,    80, "Temperature Limit", "Maximum Internal Temperature Limit"}},
				{  32, RegisterData{ 32, 2, true,  A::RW,   160, "Max Voltage Limit", "Maximum Voltage Limit"}},
				{  34, RegisterData{ 34, 2, true,  A::RW,    95, "Min Voltage Limit", "Minimum Voltage Limit"}},
				{  36, RegisterData{ 36, 2, true,  A::RW,   885, "PWM Limit", "Maximum PWM Limit"}},
				{  38, RegisterData{ 38, 2, true,  A::RW,  1941, "Current Limit", "Maximum Current Limit"}},
				{  40, RegisterData{ 40, 4, true,  A::RW, 32767, "Acceleration Limit", "Maximum Acceleration Limit"}},
				{  44, RegisterData{ 44, 4, true,  A::RW,   435, "Velocity Limit", "Maximum Velocity Limit"}},
				{  48, RegisterData{ 48, 4, true,  A::RW,  4095, "Max Position Limit", "Maximum Position Limit"}},
				{  52, RegisterData{ 52, 4, true,  A::RW,     0, "Min Position Limit", "Minimum Position Limit"}},
				{  63, RegisterData{ 63, 1, true,  A::RW,    52, "Shutdown", "Shutdown Dynamixel"}},
				{  64, RegisterData{ 64, 1, false, A::RW,     0, "Torque Enable", "Motor Torque On/Off"}},
				{  65, RegisterData{ 65, 1, false, A::RW,     0, "LED", "Status LED On/Off"}},
				{  68, RegisterData{ 68, 1, false, A::RW,     2, "Status Return Level", "Select Types of Status Return"}},
				{  69, RegisterData{ 69, 1, false, A:: R,     0, "Registered Instruction", "Check Reception of Instruction"}},
				{  70, RegisterData{ 70, 1, false, A:: R,     0, "Hardware Error Status", "Hardware Error Status"}},
				{  76, RegisterData{ 76, 2, false, A::RW,  1920, "Velocity I Gain", "I Gain of Velocity"}},
				{  78, RegisterData{ 78, 2, false, A::RW,   100, "Velocity P Gain", "P Gain of Velocity"}},
				{  80, RegisterData{ 80, 2, false, A::RW,     0, "Position D Gain", "D Gain of Position"}},
				{  82, RegisterData{ 82, 2, false, A::RW,     0, "Position I Gain", "I Gain of Position"}},
				{  84, RegisterData{ 84, 2, false, A::RW,   850, "Position P Gain", "P Gain of Position"}},
				{  88, RegisterData{ 88, 2, false, A::RW,     0, "Feedforward 2nd Gain", "2nd Gain of Feed-Forward"}},
				{  90, RegisterData{ 90, 2, false, A::RW,     0, "Feedforward 1st Gain", "1st Gain of Feed-Forward"}},
				{  98, RegisterData{ 98, 1, false, A::RW,     0, "Bus Watchdog", "Dynamixel Bus Watchdog"}},
				{ 100, RegisterData{100, 2, false, A::RW,    {}, "Goal PWM", "Target PWM Value"}},
				{ 102, RegisterData{102, 2, false, A::RW,    {}, "Goal Current", "Target Current Value"}},
				{ 104, RegisterData{104, 4, false, A::RW,    {}, "Goal Velocity", "Target Velocity Value"}},
				{ 108, RegisterData{108, 4, false, A::RW,     0, "Profile Acceleration", "Acceleration Value of Profile"}},
				{ 112, RegisterData{112, 4, false, A::RW,     0, "Profile Velocity", "Velocity Value of Profile"}},
				{ 116, RegisterData{116, 4, false, A::RW,    {}, "Goal Position", "Target Position Value"}},
				{ 120, RegisterData{120, 2, false, A:: R,    {}, "Realtime Tick", "Count Time in millisecond"}},
				{ 122, RegisterData{122, 1, false, A:: R,     0, "Moving", "Movement Status"}},
				{ 123, RegisterData{123, 1, false, A:: R,     0, "Moving Status", "Detailed Information of Movement Status"}},
				{ 124, RegisterData{124, 2, false, A:: R,    {}, "Present PWM", "Current PWM Value"}},
				{ 126, RegisterData{126, 2, false, A:: R,    {}, "Present Current", "Current Current Value"}},
				{ 128, RegisterData{128, 4, false, A:: R,    {}, "Present Velocity", "Current Velocity Value"}},
				{ 132, RegisterData{132, 4, false, A:: R,    {}, "Present Position", "Current Position Value"}},
				{ 136, RegisterData{136, 4, false, A:: R,    {}, "Velocity Trajectory", "Target Velocity Trajectory Generated by Profile"}},
				{ 140, RegisterData{140, 4, false, A:: R,    {}, "Position Trajectory", "Target Position Trajectory Generated by Profile"}},
				{ 144, RegisterData{144, 2, false, A:: R,    {}, "Present Input Voltage", "Current Input Voltage"}},
				{ 146, RegisterData{146, 1, false, A:: R,    {}, "Present Temperature", "Current Internal Temperature"}}
			}
		}},
		{321, MotorData {
			"MX106-V2",
			{"MX-106T-V2", "MX-106R-V2"},
			{
				{   0, RegisterData{  0, 2, true,  A:: R,   321, "Model Number", "Model Number"}},
				{   2, RegisterData{  2, 4, true,  A:: R,    {}, "Model Information", "Model Information"}},
				{   6, RegisterData{  6, 1, true,  A:: R,    {}, "Version of Firmware", "Firmware Version"}},
				{   7, RegisterData{  7, 1, true,  A::RW,     1, "ID", "Dynamixel ID"}},
				{   8, RegisterData{  8, 1, true,  A::RW,     1, "Baud Rate", "Communication Baud Rate"}},
				{   9, RegisterData{  9, 1, true,  A::RW,   250, "Return Delay Time", "Response Delay Time"}},
				{  10, RegisterData{ 10, 1, true,  A::RW,     0, "Drive Mode", "Drive Mode"}},
				{  11, RegisterData{ 11, 1, true,  A::RW,     3, "Operating Mode", "Operating Mode"}},
				{  12, RegisterData{ 12, 1, true,  A::RW,   255, "Secondary(Shadow) ID", "Secondary(Shadow) ID"}},
				{  13, RegisterData{ 13, 1, true,  A::RW,     2, "Protocol Version", "Protocol Version"}},
				{  20, RegisterData{ 20, 4, true,  A::RW,     0, "Homing Offset", "Home Position Offset"}},
				{  24, RegisterData{ 24, 4, true,  A::RW,    10, "Moving Threshold", "Velocity Threshold for Movement Detection"}},
				{  31, RegisterData{ 31, 1, true,  A::RW,    80, "Temperature Limit", "Maximum Internal Temperature Limit"}},
				{  32, RegisterData{ 32, 2, true,  A::RW,   160, "Max Voltage Limit", "Maximum Voltage Limit"}},
				{  34, RegisterData{ 34, 2, true,  A::RW,    95, "Min Voltage Limit", "Minimum Voltage Limit"}},
				{  36, RegisterData{ 36, 2, true,  A::RW,   885, "PWM Limit", "Maximum PWM Limit"}},
				{  38, RegisterData{ 38, 2, true,  A::RW,  2047, "Current Limit", "Maximum Current Limit"}},
				{  40, RegisterData{ 40, 4, true,  A::RW, 32767, "Acceleration Limit", "Maximum Acceleration Limit"}},
				{  44, RegisterData{ 44, 4, true,  A::RW,   360, "Velocity Limit", "Maximum Velocity Limit"}},
				{  48, RegisterData{ 48, 4, true,  A::RW,  4095, "Max Position Limit", "Maximum Position Limit"}},
				{  52, RegisterData{ 52, 4, true,  A::RW,     0, "Min Position Limit", "Minimum Position Limit"}},
				{  63, RegisterData{ 63, 1, true,  A::RW,    52, "Shutdown", "Shutdown Dynamixel"}},
				{  64, RegisterData{ 64, 1, false, A::RW,     0, "Torque Enable", "Motor Torque On/Off"}},
				{  65, RegisterData{ 65, 1, false, A::RW,     0, "LED", "Status LED On/Off"}},
				{  68, RegisterData{ 68, 1, false, A::RW,     2, "Status Return Level", "Select Types of Status Return"}},
				{  69, RegisterData{ 69, 1, false, A:: R,     0, "Registered Instruction", "Check Reception of Instruction"}},
				{  70, RegisterData{ 70, 1, false, A:: R,     0, "Hardware Error Status", "Hardware Error Status"}},
				{  76, RegisterData{ 76, 2, false, A::RW,  1920, "Velocity I Gain", "I Gain of Velocity"}},
				{  78, RegisterData{ 78, 2, false, A::RW,   100, "Velocity P Gain", "P Gain of Velocity"}},
				{  80, RegisterData{ 80, 2, false, A::RW,     0, "Position D Gain", "D Gain of Position"}},
				{  82, RegisterData{ 82, 2, false, A::RW,     0, "Position I Gain", "I Gain of Position"}},
				{  84, RegisterData{ 84, 2, false, A::RW,   850, "Position P Gain", "P Gain of Position"}},
				{  88, RegisterData{ 88, 2, false, A::RW,     0, "Feedforward 2nd Gain", "2nd Gain of Feed-Forward"}},
				{  90, RegisterData{ 90, 2, false, A::RW,     0, "Feedforward 1st Gain", "1st Gain of Feed-Forward"}},
				{  98, RegisterData{ 98, 1, false, A::RW,     0, "Bus Watchdog", "Dynamixel Bus Watchdog"}},
				{ 100, RegisterData{100, 2, false, A::RW,    {}, "Goal PWM", "Target PWM Value"}},
				{ 102, RegisterData{102, 2, false, A::RW,    {}, "Goal Current", "Target Current Value"}},
				{ 104, RegisterData{104, 4, false, A::RW,    {}, "Goal Velocity", "Target Velocity Value"}},
				{ 108, RegisterData{108, 4, false, A::RW,     0, "Profile Acceleration", "Acceleration Value of Profile"}},
				{ 112, RegisterData{112, 4, false, A::RW,     0, "Profile Velocity", "Velocity Value of Profile"}},
				{ 116, RegisterData{116, 4, false, A::RW,    {}, "Goal Position", "Target Position Value"}},
				{ 120, RegisterData{120, 2, false, A:: R,    {}, "Realtime Tick", "Count Time in millisecond"}},
				{ 122, RegisterData{122, 1, false, A:: R,     0, "Moving", "Movement Status"}},
				{ 123, RegisterData{123, 1, false, A:: R,     0, "Moving Status", "Detailed Information of Movement Status"}},
				{ 124, RegisterData{124, 2, false, A:: R,    {}, "Present PWM", "Current PWM Value"}},
				{ 126, RegisterData{126, 2, false, A:: R,    {}, "Present Current", "Current Current Value"}},
				{ 128, RegisterData{128, 4, false, A:: R,    {}, "Present Velocity", "Current Velocity Value"}},
				{ 132, RegisterData{132, 4, false, A:: R,    {}, "Present Position", "Current Position Value"}},
				{ 136, RegisterData{136, 4, false, A:: R,    {}, "Velocity Trajectory", "Target Velocity Trajectory Generated by Profile"}},
				{ 140, RegisterData{140, 4, false, A:: R,    {}, "Position Trajectory", "Target Position Trajectory Generated by Profile"}},
				{ 144, RegisterData{144, 2, false, A:: R,    {}, "Present Input Voltage", "Current Input Voltage"}},
				{ 146, RegisterData{146, 1, false, A:: R,    {}, "Present Temperature", "Current Internal Temperature"}}
			}
		}},

	};
	return data;
}

}
