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
	bool shouldStart();
private:
    uint8_t calcChecksum(uint8_t packet[], int length);
    bool shouldStartFlag;
};


#endif