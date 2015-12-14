/**
 * Subsystem that handles the IR Wiimote camera
 * @author Hans Johnson
 * @date Dec 2015
 **/

#include "FlameSense.h"

/**
 * @param xDegrees width of the camera's FOV in the x direction in degrees (camera flat)
 * @param yDegrees height of the camera's FOV in the y direction in degrees (camera flat)
 **/
FlameSense::FlameSense(int xDegrees, int yDegrees) {
	_xAngleComp = tan(xDegrees*3.1415/180)/1023;
	_yAngleComp = tan(yDegrees*3.1415/180)/1023;
}

/** 
 * Initializes camera
 **/
void FlameSense::initialize() {
	ircam.init();
}

/** 
 * @return bool True if the camera sees an IR blob
 **/
bool FlameSense::isFlame() {
	return ircam.read()&BLOB1;
}

/**
 * @return float angle to the candle in radians
 **/
float FlameSense::flameAngle() {
	ircam.read();
	return atan((512-ircam.Blob1.Y)*_yAngleComp);
}

/**
 * @return float The sine of the angle between horizontal and the IR blob
 **/
float FlameSense::flameHeightSin() {
	ircam.read();
	return sin(atan((512-ircam.Blob1.X)*_xAngleComp));
}