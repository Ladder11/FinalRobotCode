/** 
 * Subsystem that handles the various LEDs on the robot
 * @author Hans Johnson
 * @date Dec. 2015
 **/

#include "BlinkyLights.h"

/** 
 * Constructor
 * Sets up the appropriate pins
 **/
BlinkyLights::BlinkyLights() {
	pinMode(BL_LEFT_FRONT, OUTPUT);
  pinMode(BL_RIGHT_FRONT, OUTPUT);
  pinMode(BL_LEFT_FRONT_GND, OUTPUT);
  pinMode(BL_RIGHT_FRONT_GND, OUTPUT);

  pinMode(BL_LEFT_REAR, OUTPUT);
  pinMode(BL_RIGHT_REAR, OUTPUT);
  pinMode(BL_LEFT_REAR_GND, OUTPUT);
  pinMode(BL_RIGHT_REAR_GND, OUTPUT);

  pinMode(LB_LEFT, OUTPUT);
  pinMode(LB_RIGHT, OUTPUT);
}

/** 
 * Sets all the pins to low, turning all lights off
 **/
void BlinkyLights::initialize() {
	digitalWrite(BL_LEFT_FRONT, LOW);
  digitalWrite(BL_RIGHT_FRONT, LOW);
  digitalWrite(BL_LEFT_FRONT_GND, LOW);
  digitalWrite(BL_RIGHT_FRONT_GND, LOW);
  digitalWrite(BL_LEFT_REAR, LOW);
  digitalWrite(BL_RIGHT_REAR, LOW);
  digitalWrite(BL_LEFT_REAR_GND, LOW);
  digitalWrite(BL_RIGHT_REAR_GND, LOW);
  
  digitalWrite(LB_LEFT, LOW);
  digitalWrite(LB_RIGHT, LOW);
}

/** 
 * Turns on the left side red LED strip if parameter is true
 **/
void BlinkyLights::leftBar(bool on) {
	if (on) {
		digitalWrite(LB_LEFT, HIGH);
	} else {
		digitalWrite(LB_LEFT, LOW);
	}

}

/** 
 * Turns on the right side red LED strip if parameter is true
 **/
void BlinkyLights::rightBar(bool on) {
	if (on) {
		digitalWrite(LB_RIGHT, HIGH);
	} else {
		digitalWrite(LB_RIGHT, LOW);
	}
}

/** 
 * Turns on the left side yellow turn signal LEDs if parameter is true
 **/
void BlinkyLights::leftBlinkers(bool on) {
	if (on) {
		digitalWrite(BL_LEFT_FRONT, HIGH);
		digitalWrite(BL_LEFT_REAR, HIGH);
	} else {
		digitalWrite(BL_LEFT_FRONT, LOW);
		digitalWrite(BL_LEFT_REAR, LOW);
	}
}

/** 
 * Turns on the right side yellow turn signal LEDs if parameter is true
 **/
void BlinkyLights::rightBlinkers(bool on) {
	if (on) {
		digitalWrite(BL_RIGHT_FRONT, HIGH);
		digitalWrite(BL_RIGHT_REAR, HIGH);
	} else {
		digitalWrite(BL_RIGHT_FRONT, LOW);
		digitalWrite(BL_RIGHT_REAR, LOW);
	}
}

/**
 * Sets variable that controls the blinking of the red LED strip
 **/
void BlinkyLights::setLightBarBlink() {
	lightBar = true;
}

/**
 * @return bool The value of the LED strip control variable
 **/
bool BlinkyLights::getLightBarBlink() {
	return lightBar;
}