#include "FlameSense.h"

FlameSense::FlameSense(int xDegrees, int yDegrees, ultrasonic* frontSensor) {
	_xAngleComp = tan(xDegrees*3.1415/180)/1023;
	_yAngleComp = tan(yDegrees*3.1415/180)/1023;
	_frontSensor = frontSensor;
}

void FlameSense::initialize() {
	ircam.init();
}

bool FlameSense::isFlame() {
	return ircam.read()&BLOB1;
}

/**
 * Returns the angle to the candle in radians
 * @return float angle
 **/

float FlameSense::flameAngle() {
	ircam.read();
	return atan((512-ircam.Blob1.Y)*_yAngleComp);
}

float FlameSense::flameHeight() {
	ircam.read();
	return sin(atan((512-ircam.Blob1.X)*_xAngleComp))*flameDistance()+8;
}

float FlameSense::flameDistance() {
	return _frontSensor->distance(); //#TODO: Fix this function
}