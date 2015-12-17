#ifndef LADDER11TELEMETRY_H
#define LADDER11TELEMETRY_H

/** Telemetry back to a serial device
  * @author Jordan Burklund
  * @date Dec. 2015
  **/
#include <Arduino.h>
#include "Ladder11TelemetryConstants.h"

class Ladder11Telemetry {
public:
	Ladder11Telemetry();
	void sendRobotPose(float x, float y, float theta);
	void sendFlameLoc(float x, float y, float z);
	void sendCameraData(int x, int y, uint8_t size);	//#TODO send other camera values
	void sendBatteryVoltage(float voltage);
	void sendGyroOrientation(float z);
	void sendStatus(uint8_t status, uint8_t substatus);
	void sendRunning();
	void sendStopped();
	bool shouldStart();
	void readPacket();
private:
    uint8_t calcChecksum(uint8_t packet[], uint8_t length);
    void sendPacket(uint8_t packet[], uint8_t length);
    uint8_t getHighByte(int val);
    uint8_t getLowByte(int val);
    void parsePacket(uint8_t packet[], uint8_t length);
    bool shouldStartFlag;
    bool processingPacket;
    uint8_t readBuff[16];
};


#endif