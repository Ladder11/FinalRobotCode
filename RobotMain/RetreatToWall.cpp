#include "RetreatToWall.h"

RetreatToWall::RetreatToWall(float setpoint) : Command("Retreat to Wall"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void RetreatToWall::initialize() {
  // calculate theta to new position
  xDelta = ladder11->drivetrain->getCandleFoundX()-ladder11->drivetrain->getXOdoEst();
  yDelta = ladder11->drivetrain->getCandleFoundY()-ladder11->drivetrain->getYOdoEst();
  thetaDesired = tan(yDelta/xDelta);
  // turn to that position
  // drive to that position
}

void RetreatToWall::execute() {
  ladder11->drivetrain->drive(0, -30*(thetaDesired-ladder11->drivetrain->getOrientOdoEst()));
  ladder11->drivetrain->updateRobotPos();
}

bool RetreatToWall::isFinished() {

	return abs((thetaDesired-ladder11->drivetrain->getOrientOdoEst()))<10*3.14/180;
}

void RetreatToWall::end() {
	ladder11->lcd->print("Done wall");
	ladder11->drivetrain->stop();
}
