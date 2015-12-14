#include "RetreatToWallStep2.h"

RetreatToWallStep2::RetreatToWallStep2(float setpoint) : Command("Retreat to Wall"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void RetreatToWallStep2::initialize() {
  // calculate theta to new position
  //xDelta = ladder11->drivetrain->getCandleFoundX()-ladder11->drivetrain->getXOdoEst();
  //yDelta = ladder11->drivetrain->getCandleFoundY()-ladder11->drivetrain->getYOdoEst();
  //thetaDesired = tan(xDelta/yDelta)*1000;
  xDesired=ladder11->drivetrain->getCandleFoundX();
  yDesired=ladder11->drivetrain->getCandleFoundY();
  // turn to that position
  // drive to that position
}

void RetreatToWallStep2::execute() {
  xDelta = xDesired-ladder11->drivetrain->getXOdoEst();
  yDelta= yDesired-ladder11->drivetrain->getYOdoEst();
  moveSpeed = .05*sqrt(sq(xDelta)+sq(yDelta));
  if (moveSpeed > 0) {
    if (moveSpeed < 2.5) {
      moveSpeed = 2.5;
    }
  } else {
    if (moveSpeed > 5) {
      moveSpeed = 5;
    }
  }
  ladder11->drivetrain->drive(moveSpeed, 0);
  //ladder11->drivetrain->updateRobotPos();
  ladder11->lcd->clear();
  ladder11->lcd->setCursor(0,0);
  ladder11->lcd->print (sqrt(sq(xDelta)+sq(yDelta)));
  ladder11->lcd->setCursor(0,1);
  ladder11->lcd->print(xDelta);
  ladder11->lcd->setCursor(5,1);
  ladder11->lcd->print(yDelta);
  
}

bool RetreatToWallStep2::isFinished() {
	return sqrt(sq(xDelta)+sq(yDelta))<6|| ladder11->frontSensor->distance()<10 || ladder11->leftSensor->distance()<14|| ladder11->rightSensor->distance()<14 ;
}

void RetreatToWallStep2::end() {
  ladder11->drivetrain->stop();
  ladder11->lcd->clear();
  ladder11->lcd->setCursor(0, 0);
	ladder11->lcd->print(thetaDesired, DEC);
  ladder11->lcd->setCursor(0, 1);
  ladder11->lcd->print(ladder11->drivetrain->getOrientOdoEst()*1000, DEC);
  ladder11->lcd->setCursor(8, 1);
  ladder11->lcd->print(angleDelta, DEC);
  
}
