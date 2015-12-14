/** 
 * Command that controls the blinking of the various LEDs on the robot
 * @author Hans Johnson
 * @date Dec. 2015
 **/

#include "PersistentBlink.h"

PersistentBlink::PersistentBlink() : Command("Persistent Blink"){
	ladder11 = Robot::getInstance();
}

void PersistentBlink::initialize() {
	
}

/** 
 * Blinks the LED strip if it is supposed to, just the yellow turn signals otherwise
 **/
void PersistentBlink::execute() {
	if (ladder11->lights->getLightBarBlink()) {
		if (getTime()%500 > 250) {
			ladder11->lights->leftBar(true);
			ladder11->lights->rightBar(false);
			ladder11->lights->leftBlinkers(false);
			ladder11->lights->rightBlinkers(true);
		} else {
			ladder11->lights->leftBar(false);
			ladder11->lights->rightBar(true);
			ladder11->lights->leftBlinkers(true);
			ladder11->lights->rightBlinkers(false);
		}
	} else {
		if (getTime()%500 > 250) {
			ladder11->lights->leftBlinkers(false);
			ladder11->lights->rightBlinkers(true);
		} else {
			ladder11->lights->leftBlinkers(true);
			ladder11->lights->rightBlinkers(false);
		}
	}


}

/**
 * Never ends
 **/
bool PersistentBlink::isFinished() {
	return false;
}

void PersistentBlink::end() {

}