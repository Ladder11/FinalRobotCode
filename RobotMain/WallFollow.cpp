#include "WallFollow.h"

WallFollow::WallFollow(float setpoint) : Command("Wall Follow"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void WallFollow::initialize() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void WallFollow::execute() {
  if ((ladder11->frontSensor->distance() > _setpoint) && !isTurning) { // If the front sensor doesn't see a wall, and the robot isn't supposed to be turning
      turnSpeed = constrain(9*(_setpoint-ladder11->rightSensor->distance()), -40, 40);
      ladder11->drivetrain->drive(3.5, turnSpeed);
  } else {
    if (isTurning) { // If the robot is in the middle of a turn
    	if (getTime() > (turnStartTime + 3300)) {// Is the turn done?
    		isTurning = false;
    	}
    } else {
    	isTurning = true;
    	turnStartTime = getTime();
    }
    ladder11->drivetrain->drive(0, 40);
  }

  if (getTime()%500 < 250) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
}

bool WallFollow::isFinished() {

	return ladder11->flameSense->isFlame() && !isTurning;
}

void WallFollow::end() {
	ladder11->lcd->print("Done wall");
	ladder11->drivetrain->stop();
}
