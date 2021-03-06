/**
 * Command to drive back to the spot where the robot saw the candle
 **/
#include "RetreatToWallStep2.h"

RetreatToWallStep2::RetreatToWallStep2() : Command("Retreat to Wall"){
	ladder11 = Robot::getInstance();
}
/**
 * Gets the destination coordinates
 **/
void RetreatToWallStep2::initialize() {
  ladder11->telemetry->sendStatus(STATUS_RETURN_HOME, SUBSTATUS_DRIVING_TO_CANDLE_SEEN_POS);
  xDesired=ladder11->drivetrain->getCandleFoundX();
  yDesired=ladder11->drivetrain->getCandleFoundY();
}

/**
 * Drives to the position with a P controller for speed, plus max/min caps
 **/
void RetreatToWallStep2::execute() {
  xDelta = xDesired-ladder11->drivetrain->getXOdoEst();
  yDelta= yDesired-ladder11->drivetrain->getYOdoEst();
  thetaDesired=atan2(xDelta,yDelta)*1000;
  angleDelta = thetaDesired-ladder11->drivetrain->getOrientOdoEst()*1000;
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
  ladder11->drivetrain->drive(moveSpeed, -0.1*angleDelta);
//  ladder11->lcd->clear();
//  ladder11->lcd->setCursor(0,0);
//  ladder11->lcd->print(moveSpeed*20);
//  ladder11->lcd->setCursor(0,1);
//  ladder11->lcd->print(angleDelta);
  //ladder11->lcd->setCursor(5,1);
  //ladder11->lcd->print(yDelta);
}

/**
 * Finishes if the robot gets close to the correct position, or the front sensor sees the wall
 **/
bool RetreatToWallStep2::isFinished() {
	return sqrt(sq(xDelta)+sq(yDelta))<2 || ladder11->frontSensor->distance()<10; //|| ladder11->leftSensor->distance()<14;
}

void RetreatToWallStep2::end() {
  ladder11->drivetrain->stop();
/*  ladder11->lcd->clear();
  ladder11->lcd->setCursor(0, 0);
  ladder11->lcd->print(thetaDesired, DEC);
  ladder11->lcd->setCursor(0, 1);
  ladder11->lcd->print(ladder11->drivetrain->getOrientOdoEst()*1000, DEC);
  ladder11->lcd->setCursor(8, 1);
  ladder11->lcd->print(angleDelta, DEC);*/
  
}
