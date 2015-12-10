#include "WallFollowToStart.h"

WallFollowToStart::WallFollowToStart(float setpoint) : Command("Wall Follow"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void WallFollowToStart::initialize() {

}

void WallFollowToStart::execute() {
	if ((ladder11->frontSensor->distance() > _setpoint) && !isTurning) { // If the front sensor doesn't see a wall, and the robot isn't supposed to be turning
		ladder11->drivetrain->drive(3.5, 12*(_setpoint-ladder11->rightSensor->distance()));
	} else {
		if (isTurning) { // If the robot is in the middle of a turn
			if (getTime() > (turnStartTime + 2000)) {// Is the turn done?
				isTurning = false;
			}
		} else {
			isTurning = true;
			turnStartTime = getTime();
		}
		ladder11->drivetrain->drive(0, 50);
	}
}

bool WallFollowToStart::isFinished() {

	return abs(ladder11->drivetrain->getXOdoEst())<4 && abs(ladder11->drivetrain->getYOdoEst()<4);
}

void WallFollowToStart::end() {
	ladder11->lcd->print("Done wall");
	ladder11->drivetrain->stop();
}