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

void WallFollow::initialize() {}

/** 
 * Uses proportional controller to control turn rate
 **/
void WallFollow::execute() {
  if ((ladder11->frontSensor->distance() > _setpoint) && !isTurning) { // If the front sensor doesn't see a wall, and the robot isn't supposed to be turning
      turnSpeed = constrain(10*(_setpoint-ladder11->rightSensor->distance()), -40, 40);
      ladder11->drivetrain->drive(3.5, turnSpeed);
  } else {
    if (isTurning) { // If the robot is in the middle of a turn
    	if (getTime() > (turnStartTime + 3000)) {// Is the turn done?
    		isTurning = false;
    	}
    } else {
    	isTurning = true;
    	turnStartTime = getTime();
    }
    ladder11->drivetrain->drive(0, 50);
  }
}

/** 
 * Returns true when the flame sensor detects a flame
 **/
bool WallFollow::isFinished() {
	return ladder11->flameSense->isFlame() && !isTurning;
}

/**
 * Stops the robot and turns on the LED strip to indicate the flame is found
 **/
void WallFollow::end() {
	ladder11->lcd->print("Done wall");
	ladder11->drivetrain->stop();
  ladder11->lights->setLightBarBlink();
}