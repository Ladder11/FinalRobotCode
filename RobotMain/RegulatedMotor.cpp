#include "RegulatedMotor.h"

/** Constructor
  * @param KitMotor motor The motor object to use for output
  * @param KitEncoder encoder The encoder object to use for reading motion
  * @param float gearboxRatio The torque ratio of the gearbox attached to the motor (a 50:1 gearbox would have 50 for this parameter)
  * @param float encoderCounts The number of encoder counts per revolution of the motor shaft (not gearbox shaft)
  **/
RegulatedMotor::RegulatedMotor(int motorFPin, int motorRPin, int encoderSS) {
	_motor = new KitMotor(motorFPin, motorRPin);
	_encoder = new KitEncoder(encoderSS);
}

/**
 * Assumes that the motor and encoder have already been initialized
 **/
void RegulatedMotor::initialize() { 
}

/**
 * Moves the motor at the specified speed
 * @param float The rotational speed to move the motor at, uses a simple P controller
**/
void RegulatedMotor::setRPM(float rpms) {
	if (rpms != 0.0) {
		arpm = getRPM();
		//Serial.println(arpm);
		newOut = out + 0.005*(rpms-arpm);
		//Serial.println(newOut);
		//Serial.println(newOut);
		out = constrain(newOut, -1.0, 1.0);
		_motor->setOutput(out);
	} else {
		_motor->setOutput(0.0);
	}
}

/**
 * Returns the average RPM since the last time this function was called
 * @return float The average RPM of this motor since last function call
 **/
float RegulatedMotor::getRPM() {
	currentCount = _encoder->getCount();
	currentTime = millis();
	avgRPM = ((currentCount-lastCount)*scaleFactor)/(currentTime-lastTime); // ((Motor shaft turns)/Gearbox)/(time delta in minutes)
	lastCount = currentCount;
	lastTime = currentTime;
	return avgRPM;
}

/**
 * Wrapper for getRPM()
 * @return bool Returns true if the average RPM since the last call is zero
 **/
bool RegulatedMotor::isStalled() {
	return getRPM() == 0;
}

/**
 * @return long Current count of the encoder attached to this motor
 **/
float RegulatedMotor::getRevolutions() {
	return _encoder->getCount()/encoderCounts/gearboxRatio;
}