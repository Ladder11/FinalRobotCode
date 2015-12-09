#include "BlinkyLights.h"

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

void BlinkyLights::leftBar(bool on) {
	if (on) {
		digitalWrite(LB_LEFT, HIGH);
	} else {
		digitalWrite(LB_LEFT, LOW);
	}

}

void BlinkyLights::rightBar(bool on) {
	if (on) {
		digitalWrite(LB_RIGHT, HIGH);
	} else {
		digitalWrite(LB_RIGHT, LOW);
	}
}

void BlinkyLights::leftBlinkers(bool on) {
	if (on) {
		digitalWrite(BL_LEFT_FRONT, HIGH);
		digitalWrite(BL_LEFT_REAR, HIGH);
	} else {
		digitalWrite(BL_LEFT_FRONT, LOW);
		digitalWrite(BL_LEFT_REAR, LOW);
	}
}

void BlinkyLights::rightBlinkers(bool on) {
	if (on) {
		digitalWrite(BL_RIGHT_FRONT, HIGH);
		digitalWrite(BL_RIGHT_REAR, HIGH);
	} else {
		digitalWrite(BL_RIGHT_FRONT, LOW);
		digitalWrite(BL_RIGHT_REAR, LOW);
	}
}

void BlinkyLights::setLightBarBlink() {
	lightBar = true;
}

bool BlinkyLights::getLightBarBlink() {
	return lightBar;
}