#include "WallFollowToStart.h"

WallFollowToStart::WallFollowToStart(float setpoint) : Command("Wall Follow"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void WallFollowToStart::initialize() {

}

void WallFollowToStart::execute() {
  if ((ladder11->frontSensor->distance() > _setpoint) && !isTurning) { // If the front sensor doesn't see a wall, and the robot isn't supposed to be turning
      distErr = _setpoint-ladder11->leftSensor->distance();
      output = 9*distErr + 3*(prevDistErr-distErr);
      prevDistErr = distErr;
      turnSpeed = constrain(output, -40, 40);
      ladder11->drivetrain->drive(3.5, -turnSpeed);
  } else {
    if (isTurning) { // If the robot is in the middle of a turn
    if (ladder11->rightSensor->distance()>6&&ladder11->leftSensor->distance()<10) {// Is the turn done?
        isTurning = false;
      }
    } else {
      isTurning = true;
      turnStartTime = getTime();
    }
    ladder11->drivetrain->drive(0, -25);
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

	return sqrt(sq(ladder11->drivetrain->getXOdoEst())+sq(ladder11->drivetrain->getXOdoEst()))<6;
}

void WallFollowToStart::end() {
	ladder11->lcd->print(sqrt(sq(ladder11->drivetrain->getXOdoEst())+sq(ladder11->drivetrain->getXOdoEst())));
	ladder11->drivetrain->stop();
}
