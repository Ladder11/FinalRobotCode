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
uint8_t Ladder11Telemetry::calcChecksum(uint8_t packet[], int length) {
	uint8_t sum = 0;
	for(int i=0; i<(length-1); i++) {
		sum += packet[i];
	}
	return sum;
}

/** Sends the pose data of the robot composed of the
  * X, Y, and theta values of the robot's position in units of inches & degrees
  * @param x X value of the robot's current position
  * @param y Y value of the robot's current position
  * @param theta Theta value of the robot's current orientation
  **/
void Ladder11Telemetry::sendRobotPose(float x, float y, float theta) {
	uint8_t packet[13];
	packet[0] = START_BYTE;
	packet[1] = 13;
	packet[2] = COMMAND_ROBOT_POSE;
	//#TODO fix known negative issue
	int intPart = (int) x;
	int decPart = ((int) (x*100.0)) - 100*intPart;
	if(decPart < 0) 	//change to the correct sign
		decPart *= -1; 
	packet[3] = (intPart >> 8) & 0xFF;
	packet[4] = (uint8_t) (intPart & 0xFF);
	packet[5] = (uint8_t) decPart;
	intPart = (int) y;
	decPart = ((int) (y*100.0)) - 100*intPart;
	if(decPart < 0) 	//change to the correct sign
		decPart *= -1; 
	packet[6] = (intPart >> 8) & 0xFF;
	packet[7] = (uint8_t) (intPart & 0xFF);
	packet[8] = (uint8_t) decPart;
	intPart = (int) theta;
	decPart = ((int) (theta*100.0)) - 100*intPart;
	if(decPart < 0) 	//change to the correct sign
		decPart *= -1; 
	packet[9] = (intPart >> 8) & 0xFF;
	packet[10] = (uint8_t) (intPart & 0xFF);
	packet[11] = (uint8_t) decPart;
	packet[12] = calcChecksum(packet, 13);

	for(int i=0; i<13; i++) {
		Serial3.write(packet[i]);
		Serial.println(packet[i], DEC);
	}
}