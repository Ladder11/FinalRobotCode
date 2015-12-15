/**
 * Command to follow the wall on the left side of the robot back to the starting location within a set tolerance
 **/

#include "WallFollowToStart.h"

/**
 * @param setpoint The distance at which to follow the wall from
 **/
WallFollowToStart::WallFollowToStart(float setpoint) : Command("Wall Follow"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void WallFollowToStart::initialize() {
  ladder11->telemetry->sendStatus(STATUS_RETURN_HOME, SUBSTATUS_WALLFOLLOW);
}

/**
 * Handles the actual wall following with a PD controller, and a simple 2 state turning or wall following state machine
 * Maximum turn rate is capped while wall following, the turn at this forward speed/turn rate makes a nice turn around an outside corner
 **/
void WallFollowToStart::execute() {
//    ladder11->lcd->clear();
    if ((ladder11->frontSensor->distance() > _setpoint) && !isTurning) { // If the front sensor doesn't see a wall, and the robot isn't supposed to be turning
        distErr = _setpoint-ladder11->leftSensor->distance();
        output = 9*distErr + 3*(prevDistErr-distErr);
        prevDistErr = distErr;
        turnSpeed = constrain(output, -40, 40);
      	if (ladder11->leftSensor->distance() > (_setpoint + 2) && ladder11->leftSensor->distance() < (_setpoint + 5)) {
      	  turnSpeed = constrain(turnSpeed, -15, 15);
      	  ladder11->telemetry->sendStatus(STATUS_RETURN_HOME, SUBSTATUS_TOOFARFROMWALL);
      	} else {
      	  ladder11->telemetry->sendStatus(STATUS_RETURN_HOME, SUBSTATUS_WALLFOLLOW);
      	}
        ladder11->drivetrain->drive(3.5, -turnSpeed);
    } else { // If the robot sees a wall, or the robot is already turning
      if (isTurning) {
        if (ladder11->leftSensor->distance()>6&&ladder11->leftSensor->distance()<10) {// Is the turn done?
          isTurning = false;
        }
      } else {
        isTurning = true;
        turnStartTime = getTime();
      }
      ladder11->drivetrain->drive(0, -35);
    }
  //}
  //ladder11->lcd->clear();
  //ladder11->lcd->setCursor(0,0);
  //ladder11->lcd->print(ladder11->drivetrain->getXOdoEst());
  //ladder11->lcd->setCursor(0,1);
  //ladder11->lcd->print(ladder11->drivetrain->getYOdoEst());
}

/**
 * Finished when the robot is within 7" of the origin
 **/
bool WallFollowToStart::isFinished() {
	ladder11->lcd->clear();
	ladder11->lcd->print(sqrt(sq(ladder11->drivetrain->getXOdoEst())+ladder11->drivetrain->getYOdoEst()));
	return sqrt(sq(ladder11->drivetrain->getXOdoEst())+ladder11->drivetrain->getYOdoEst())<5;
}

void WallFollowToStart::end() {
	ladder11->lcd->print("Done");
	ladder11->drivetrain->stop();
	ladder11->telemetry->sendStatus(STATUS_HOME, 0);
}
