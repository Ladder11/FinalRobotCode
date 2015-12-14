/** 
 * Command to center the robot on the flame and drive to a particular distance away
 * @author Hans Johnson
 * @date Dec. 2015
 **/
#include "ApproachFlame.h"

/**
 * Constructor
 **/

ApproachFlame::ApproachFlame() : Command("Approach Flame"){
	ladder11 = Robot::getInstance();
}

void ApproachFlame::initialize() {}

/**
 * Uses a proportional controller for both linear speed and turn rate based on distance and angle to the candle
 * Linear speed has max and min caps to ensure motion and turning ability
 **/
void ApproachFlame::execute() {
  if (ladder11->flameSense->isFlame()) {
    distSpeed = .25*(ladder11->frontSensor->distance()-20);
    if (distSpeed > 5) {
    distSpeed = 5;
    }
    if (distSpeed < 1.5) {
     distSpeed = 1.5;
    }
    ladder11->drivetrain->drive(distSpeed, ladder11->flameSense->flameAngle()*180/3.1415*4);
  } else {
    ladder11->drivetrain->drive(0, 50);
  }
  ladder11->drivetrain->updateRobotPos();
  ladder11->lcd->clear();
  ladder11->lcd->print(ladder11->frontSensor->distance(), DEC);

}

/** 
 * Returns true if the angle and distance are within tolerance
 **/
bool ApproachFlame::isFinished() {
	return (abs(ladder11->flameSense->flameAngle()*180/3.14) < 10) && (ladder11->frontSensor->distance() < 20);
}

/**
 * Stops the robot's motion and prints a notification to the LCD
 **/
void ApproachFlame::end() {
	ladder11->lcd->print("Flame ahead");
	ladder11->drivetrain->stop();
}