#include "WallFollow.h"

WallFollow::WallFollow(int setpoint) : Command("Wall Follow"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void WallFollow::initialize() {

}

void WallFollow::execute(){
	if ((ladder11->frontSensor->distance() > _setpoint) && !isTurning) { // If the front sensor doesn't see a wall, and the robot isn't supposed to be turning
		ladder11->drivetrain->drive(3.5, 12*(_setpoint-ladder11->rightSensor->distance()));
	} else {
		if (isTurning) { // If the robot is in the middle of a turn
			if (getTime() > (turnStartTime + 500)) // Is the turn done?
				isTurning = false;
		} else {
			isTurning = true;
			turnStartTime = getTime();
		}
		ladder11->drivetrain->drive(0, 10);
	}
}

bool WallFollow::isFinished() {
	return ladder11->flameSense->isFlame();
}

void WallFollow::end() {
	ladder11->drivetrain->stop();
}