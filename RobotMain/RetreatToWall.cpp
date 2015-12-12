#include "RetreatToWall.h"

RetreatToWall::RetreatToWall(float setpoint) : Command("Retreat to Wall"){
	ladder11 = Robot::getInstance();
	_setpoint = setpoint;
}

void RetreatToWall::initialize() {

}

void RetreatToWall::execute() {
 if (ladder11->frontSensor->distance()<100) {
    distSpeed = .25*(ladder11->frontSensor->distance()-20);
    if (distSpeed > 5) {
    distSpeed = 5;
    }
    if (distSpeed < 1.5) {
     distSpeed = 1.5;
    }
    ladder11->drivetrain->drive(distSpeed, 0);
  } else {
    ladder11->drivetrain->drive(0, 40);
  }
  ladder11->drivetrain->updateRobotPos();
  //Print distance on the lcd screen. 
  ladder11->lcd->clear();
  ladder11->lcd->print(ladder11->frontSensor->distance(), DEC);
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

bool RetreatToWall::isFinished() {

	return abs(ladder11->frontSensor->distance()<10);
}

void RetreatToWall::end() {
	ladder11->lcd->print("Done wall");
	ladder11->drivetrain->stop();
}
