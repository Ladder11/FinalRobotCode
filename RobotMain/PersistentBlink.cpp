#include "PersistentBlink.h"

PersistentBlink::PersistentBlink() : Command("Persistent Blink"){
	ladder11 = Robot::getInstance();
}

void PersistentBlink::initialize() {
	
}

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

bool PersistentBlink::isFinished() {
	return false;
}

void PersistentBlink::end() {

}