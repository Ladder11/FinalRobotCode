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
private:
    uint8_t calcChecksum(uint8_t packet[], int length);
    bool shouldStartFlag;
};


#endif