#ifndef FLAMESENSE
#define FLAMESENSE
#include <Arduino.h>
#include <PVision.h>
#include "ultrasonic.h"

class FlameSense {
	public: 
		FlameSense(int xDegrees, int yDegrees, ultrasonic* frontSensor);
		void initialize();
		bool isFlame();
		float flameAngle();
		float flameHeight();
		float flameDistance();
	private:
		float _xAngleComp, _yAngleComp;
		ultrasonic* _frontSensor;
		PVision ircam;
};
#endif