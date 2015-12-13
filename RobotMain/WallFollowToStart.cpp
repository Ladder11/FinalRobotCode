#include "WallFollowToStart.h"

WallFollowToStart::WallFollowToStart(float setpoint) : Command("Wall Follow"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void WallFollowToStart::initialize() {

}

void WallFollowToStart::execute() {
  if ((ladder11->frontSensor->distance() > _setpoint) && !isTurning) { // If the front sensor doesn't see a wall, and the robot isn't supposed to be turning
      turnSpeed = constrain(9*(_setpoint-ladder11->leftSensor->distance()), -30, 30);
      ladder11->drivetrain->drive(3.5, -turnSpeed);
  } else {
    if (isTurning) { // If the robot is in the middle of a turn
     if (getTime() > (turnStartTime + 3300)) {// Is the turn done?
        isTurning = false;
      }
    } else {
      isTurning = true;
      turnStartTime = getTime();
    }
    ladder11->drivetrain->drive(0, -40);
  }

  if (getTime()%500 < 250) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  ladder11->lcd->clear();
  ladder11->lcd->setCursor(0,0);
  ladder11->lcd->print(ladder11->drivetrain->getXOdoEst());
  ladder11->lcd->setCursor(0,1);
  ladder11->lcd->print(ladder11->drivetrain->getYOdoEst());
}

bool WallFollowToStart::isFinished() {

	return abs(ladder11->drivetrain->getXOdoEst())<5 && abs(ladder11->drivetrain->getYOdoEst()<5);
}

void WallFollowToStart::end() {
	ladder11->lcd->print("Done wall");
	ladder11->drivetrain->stop();
}
