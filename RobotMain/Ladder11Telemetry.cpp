#include "Ladder11Telemetry.h"

/** Handles telemetry data for the Ladder11 robot.
  * Robot can send and receive data back and forth over a serial connection
  * @author Jordan Burklund
  * @date Dec. 2015

/** Constructor
  * #TODO parameter for which serial device to use, and the baud rate
  **/
Ladder11Telemetry::Ladder11Telemetry() {
	Serial3.begin(115200);
	Serial.begin(115200);
	shouldStartFlag = false;
}

/** Calculates the checksum for the given packet
  * @param packet Packet to calculate the checksum on
  * @param length Number of bytes in the packet
  * @return 8-bit sum of the bytes in the packet
  **/
uint8_t Ladder11Telemetry::calcChecksum(uint8_t packet[], uint8_t length) {
	uint8_t sum = 0;
	for(int i=0; i<(length-1); i++) {
		sum += packet[i];
	}
	return sum;
}

/** Sends the given packet
  * @param packet Packet to be sent
  * @param length Number of bytes in the packet
  **/
void Ladder11Telemetry::sendPacket(uint8_t packet[], uint8_t length) {
	for(int i=0; i<length; i++) {
		Serial3.write(packet[i]);
		Serial.println(packet[i], DEC);
	}
}

/** Returns the upper 8-bits from the integer
  * @param val Integer value to get the most significant 8 bits
  * @return byte representing the upper 8 bits of the integer
  **/
uint8_t Ladder11Telemetry::getHighByte(int val) {
	return (uint8_t) (val >>8);
}

/** Returns the lower 8-bits from the integer
  * @param val Integer value to get the least significant 8 bits
  * @return byte representing the lower 8 bits of the integer
  **/
uint8_t Ladder11Telemetry::getLowByte(int val) {
	return (uint8_t) (val & 0xFF);
}

/** Sends the pose data of the robot composed of the
  * X, Y, and theta values of the robot's position in units of inches & degrees
  * @param x X value of the robot's current position
  * @param y Y value of the robot's current position
  * @param theta Theta value of the robot's current orientation
  **/
void Ladder11Telemetry::sendRobotPose(float x, float y, float theta) {
	uint8_t packet[LEN_ROBOT_POSE];
	packet[0] = START_BYTE;
	packet[1] = LEN_ROBOT_POSE;
	packet[2] = COMMAND_ROBOT_POSE;
	//#TODO fix known negative issue
	int intPart = (int) x;
	int decPart = ((int) (x*100.0)) - 100*intPart;
	if(decPart < 0) {	//change to the correct sign
		decPart *= -1;
	}
	packet[3] = getHighByte(intPart);
	packet[4] = getLowByte(intPart);
	packet[5] = getLowByte(decPart);
	intPart = (int) y;
	decPart = ((int) (y*100.0)) - 100*intPart;
	if(decPart < 0) {	//change to the correct sign
		decPart *= -1;
	}
	packet[6] = getHighByte(intPart);
	packet[7] = getLowByte(intPart);
	packet[8] = getLowByte(decPart);
	intPart = (int) theta;
	decPart = ((int) (theta*100.0)) - 100*intPart;
	if(decPart < 0) {	//change to the correct sign
		decPart *= -1;
	}
	packet[9] = getHighByte(intPart);
	packet[10] = getLowByte(intPart);
	packet[11] = getLowByte(decPart);
	packet[12] = calcChecksum(packet, LEN_ROBOT_POSE);

	sendPacket(packet, LEN_ROBOT_POSE);
}

/** Sends the detected location of the flame
  * @param x X location of the flame
  * @param y Y location of the flame
  * @param z Z position of the flame (height)
  **/
void Ladder11Telemetry::sendFlameLoc(float x, float y, float z) {
	uint8_t packet[LEN_FLAME_LOC];
	packet[0] = START_BYTE;
	packet[1] = LEN_FLAME_LOC;
	packet[2] = COMMAND_FLAME_LOC;
	//#TODO fix known negative issue
	int intPart = (int) x;
	int decPart = ((int) (x*100.0)) - 100*intPart;
	if(decPart < 0) {	//change to the correct sign
		decPart *= -1;
	} 
	packet[3] = getHighByte(intPart);
	packet[4] = getLowByte(intPart);
	packet[5] = getLowByte(decPart);
	intPart = (int) y;
	decPart = ((int) (y*100.0)) - 100*intPart;
	if(decPart < 0) {	//change to the correct sign
		decPart *= -1;
	}
	packet[6] = getHighByte(intPart);
	packet[7] = getLowByte(intPart);
	packet[8] = getLowByte(decPart);
	intPart = (int) z;
	decPart = ((int) (z*100.0)) - 100*intPart;
	if(decPart < 0) {	//change to the correct sign
		decPart *= -1;
	}
	packet[9] = getHighByte(intPart);
	packet[10] = getLowByte(intPart);
	packet[11] = getLowByte(decPart);
	packet[12] = calcChecksum(packet, LEN_FLAME_LOC);

	sendPacket(packet, LEN_FLAME_LOC);
}

/** Sends the location of blob 1 in the camera's view
  * @param x X position of the blob
  * @param y Y position of the blob
  * @param size Size of the blob
  **/
void Ladder11Telemetry::sendCameraData(int x, int y, uint8_t size) {
	uint8_t packet[LEN_CAMERA_DATA];
	packet[0] = START_BYTE;
	packet[1] = LEN_CAMERA_DATA;
	packet[2] = COMMAND_CAMERA_DATA;
	packet[3] = getHighByte(x);
	packet[4] = getLowByte(x);
	packet[5] = getHighByte(y);
	packet[6] = getLowByte(y);
	packet[7] = size;
	packet[8] = calcChecksum(packet, LEN_CAMERA_DATA);

	sendPacket(packet, LEN_CAMERA_DATA);
}

/** Sends the battery voltage
  * @param voltage Battery voltage in volts
  **/
void Ladder11Telemetry::sendBatteryVoltage(float voltage) {
	uint8_t packet[LEN_BATT_VOLT];
	packet[0] = START_BYTE;
	packet[1] = LEN_BATT_VOLT;
	packet[2] = COMMAND_BATT_VOLT;
	int intPart = (int) voltage;
	int decPart = ((int) (voltage*100)) - (intPart*100);
	if(decPart < 0) {	//change to the correct sign
		decPart *= -1;
	}
	packet[3] = getHighByte(intPart);
	packet[4] = getLowByte(intPart);
	packet[5] = getLowByte(decPart);
	packet[6] = calcChecksum(packet, LEN_BATT_VOLT);

	sendPacket(packet, LEN_BATT_VOLT);
}

/** Sends the gyro orientation
  * @param z Rotation in degrees around the z axis
  **/
void Ladder11Telemetry::sendGyroOrientation(float z) {
	uint8_t packet[LEN_GYRO_DATA];
	packet[0] = START_BYTE;
	packet[1] = LEN_GYRO_DATA;
	packet[2] = COMMAND_GYRO_DATA;
	int intPart = (int) z;
	int decPart = ((int) (z*100)) - (intPart*100);
	if(decPart < 0) {  //change to the correct sign
		decPart *= -1;
	}
	packet[3] = getHighByte(intPart);
	packet[4] = getLowByte(intPart);
	packet[5] = getLowByte(decPart);
	packet[6] = calcChecksum(packet, LEN_GYRO_DATA);

	sendPacket(packet, LEN_GYRO_DATA);
}

/** Sends the current robot status
  * @param status Status of the robot: e.g. wall following, extinguishing flame, etc.
  * @param subStatus optional substatus of the robot: wall following turning left, etc.
  **/
void Ladder11Telemetry::sendStatus(uint8_t status, uint8_t substatus) {
	uint8_t packet[LEN_STATUS];
	packet[0] = START_BYTE;
	packet[1] = LEN_STATUS;
	packet[2] = COMMAND_STATUS;
	packet[3] = status;
	packet[4] = substatus;
	packet[5] = calcChecksum(packet, LEN_STATUS);

	sendPacket(packet, LEN_STATUS);
}

/** Sends a message that the robot is running
  **/
void Ladder11Telemetry::sendRunning() {
	uint8_t packet[LEN_RUNNING];
	packet[0] = START_BYTE;
	packet[1] = LEN_RUNNING;
	packet[2] = COMMAND_RUNNING;
	packet[3] = calcChecksum(packet, LEN_RUNNING);

	sendPacket(packet, LEN_RUNNING);
}

/** Sends a message that the robot has stopped
  **/
void Ladder11Telemetry::sendStopped() {
	uint8_t packet[LEN_STOPPED];
	packet[0] = START_BYTE;
	packet[1] = LEN_STOPPED;
	packet[2] = COMMAND_STOPPED;
	packet[3] = calcChecksum(packet, LEN_STOPPED);

	sendPacket(packet, LEN_STOPPED);
}

/** Returns a boolean if the robot should start.  Typically
  * used to initially start the robot remotely
  * @return True if the robot should start
  **/
boolean Ladder11Telemetry::shouldStart() {
	return shouldStartFlag;
}