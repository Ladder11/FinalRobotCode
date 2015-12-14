#include "RetreatToWall.h"

RetreatToWall::RetreatToWall(float setpoint) : Command("Retreat to Wall"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void RetreatToWall::initialize() {
  // calculate theta to new position
  xDelta = ladder11->drivetrain->getCandleFoundX()-ladder11->drivetrain->getXOdoEst();
  yDelta = ladder11->drivetrain->getCandleFoundY()-ladder11->drivetrain->getYOdoEst();
  thetaDesired = tan(xDelta/yDelta)*1000;
  // turn to that position
  // drive to that position
}

void RetreatToWall::execute() {
  angleDelta = thetaDesired-(ladder11->drivetrain->getOrientOdoEst())*1000;
  turnSpeed = -0.075*angleDelta;
  if (turnSpeed > 0) {
    if (turnSpeed < 25) {
      turnSpeed = 25;
    }
  } else {
    if (turnSpeed > -25) {
      turnSpeed = -25;
    }
  }
  ladder11->drivetrain->drive(0, -0.075*(angleDelta));
  ladder11->drivetrain->updateRobotPos();
}

bool RetreatToWall::isFinished() {
	return angleDelta<75 && angleDelta>-75;
}

void RetreatToWall::end() {
  ladder11->drivetrain->stop();
//  ladder11->lcd->clear();
//  ladder11->lcd->setCursor(0, 0);
//	ladder11->lcd->print(thetaDesired, DEC);
//  ladder11->lcd->setCursor(0, 1);
//  ladder11->lcd->print(ladder11->drivetrain->getOrientOdoEst()*1000, DEC);
//  ladder11->lcd->setCursor(8, 1);
//  ladder11->lcd->print(angleDelta, DEC);
}
