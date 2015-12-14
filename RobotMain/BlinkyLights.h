#ifndef BLINKYLIGHTS
#define BLINKYLIGHTS
#include <Arduino.h>
#include "RobotConstants.h"

class BlinkyLights {
	public: 
		BlinkyLights();
		void initialize();
		void leftBar(bool on);
		void rightBar(bool on);
		void leftBlinkers(bool on);
		void rightBlinkers(bool on);
		void setLightBarBlink();
		bool getLightBarBlink();
	private:
		bool lightBar = false;
};
#endif