/**
 * Command to turn back to the position at which we first saw the candle. We know there will be no obstacles or walls along this path
 **/
#include "RetreatToWall.h"

RetreatToWall::RetreatToWall() : Command("Retreat to Wall"){
  ladder11 = Robot::getInstance();
}

/**
 * Calculates the orientation from the current location to the point where the robot first saw the candle
 **/
void RetreatToWall::initialize() {
  // calculate theta to new position
  xDelta = ladder11->drivetrain->getCandleFoundX()-ladder11->drivetrain->getXOdoEst();
  yDelta = ladder11->drivetrain->getCandleFoundY()-ladder11->drivetrain->getYOdoEst();
  thetaDesired = (tan(xDelta/yDelta)+3.1415)*1000;
  // turn to that position
  // drive to that position
}

/**
 * Turns to the correct orientation using a P controller, with max/min speed caps
 **/
void RetreatToWall::execute() {
  angleDelta = thetaDesired-(ladder11->drivetrain->getOrientOdoEst())*1000;
  turnSpeed = -0.075*angleDelta;
  if (turnSpeed > 0) {
    if (turnSpeed < 35) {
      turnSpeed = 35;
    }
  } else {
    if (turnSpeed > -35) {
      turnSpeed = -35;
    }
  }
  ladder11->drivetrain->drive(0, -0.075*(angleDelta));
//  ladder11->drivetrain->updateRobotPos();
}

/**
 * Finishes when the robot is within 0.075 radians, or about 4 degrees
 **/
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
