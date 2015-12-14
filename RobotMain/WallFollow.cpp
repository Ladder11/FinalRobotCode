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
      distErr = _setpoint-ladder11->rightSensor->distance();
      output = 9*distErr + 3*(prevDistErr-distErr);
      prevDistErr = distErr;
      turnSpeed = constrain(output, -40, 40);
      ladder11->drivetrain->drive(3.5, turnSpeed);
  } else {
    if (isTurning) { // If the robot is in the middle of a turn
    	if (ladder11->rightSensor->distance()>6&&ladder11->rightSensor->distance()<10) {// Is the turn done?
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
  ladder11->lcd->clear();
  ladder11->lcd->print(ladder11->drivetrain->getOrientOdoEst());
}

bool WallFollow::isFinished() {

	return ladder11->flameSense->isFlame()&& ((8.0+ladder11->flameSense->flameHeightSin()*(ladder11->frontSensor->distance()))<14);
}

void WallFollow::end() {
	ladder11->drivetrain->setCandleFoundX();
  ladder11->drivetrain->setCandleFoundY();
	ladder11->lcd->print("Done wall");
	ladder11->drivetrain->stop();
}
