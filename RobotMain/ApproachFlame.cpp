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
 //delay(500);
  if (ladder11->flameSense->isFlame()) {
    //delay(100);
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
  //Print distance on the lcd screen. 
  ladder11->lcd->clear();
  ladder11->lcd->print(ladder11->frontSensor->distance(), DEC);
<<<<<<< HEAD
  ladder11->lcd->setCursor(0,1);
  ladder11->lcd->print(8.0+ladder11->flameSense->flameHeightSin()*(ladder11->frontSensor->distance())<14);
  //This part is just for the LEDs
  if (getTime()%500 < 250) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(32, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(46, HIGH);
    digitalWrite(48, HIGH);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(32, LOW);
    digitalWrite(34, LOW);
    digitalWrite(46, LOW);
    digitalWrite(48, LOW);
  }
}
//End condition for approaching the flame is when the flame is within 10 degrees of center of the robot and within set distance
=======

}

/** 
 * Returns true if the angle and distance are within tolerance
 **/
>>>>>>> refs/remotes/origin/master
bool ApproachFlame::isFinished() {
	return (abs(ladder11->flameSense->flameAngle()*180/3.14) < 10) && (ladder11->frontSensor->distance() < 20);
}

/**
 * Stops the robot's motion and prints a notification to the LCD
 **/
void ApproachFlame::end() {
	ladder11->lcd->print("Flame ahead");
	ladder11->drivetrain->stop();
<<<<<<< HEAD
  digitalWrite(32, LOW);
  digitalWrite(34, LOW);
  digitalWrite(46, LOW);
  digitalWrite(48, LOW);
}
=======
}
>>>>>>> refs/remotes/origin/master
