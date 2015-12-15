/** 
 * Command to follow the wall using the ultrasonic sensor
 * @author Garrison Hefter
 * @date Dec. 2015
 **/

#include "WallFollow.h"

/** 
 * @param setpoint The distance in inches that the robot should stay from the wall
 **/
WallFollow::WallFollow(float setpoint) : Command("Wall Follow"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void WallFollow::initialize() {
  ladder11->telemetry->sendStatus(STATUS_WALLFOLLOW, 0);
}

/** 
 * Uses proportional controller to control turn rate
 **/
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

//  ladder11->lcd->clear();
//  ladder11->lcd->print(ladder11->drivetrain->getOrientOdoEst());

}

/** 
 * Returns true when the flame sensor detects a flame
 **/
bool WallFollow::isFinished() {
  return ladder11->flameSense->isFlame() /* && (ladder11->rightSensor->distance() > 15)*/ && ((cameraHeight+ladder11->flameSense->flameHeightSin()*(ladder11->frontSensor->distance()))<17);
}

/**
 * Stops the robot and turns on the LED strip to indicate the flame is found
 **/
void WallFollow::end() {
  ladder11->drivetrain->setCandleFoundX();
  ladder11->drivetrain->setCandleFoundY();
  ladder11->lcd->print("Done wall");
  ladder11->drivetrain->stop();
  ladder11->lights->setLightBarBlink();
}
