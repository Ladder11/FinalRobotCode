#include "ApproachFlame.h"

ApproachFlame::ApproachFlame() : Command("Approach Flame"){
	ladder11 = Robot::getInstance();
}

void ApproachFlame::initialize() {
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(33, LOW);
  digitalWrite(35, LOW);
  digitalWrite(47, LOW);
  digitalWrite(59, LOW);
}

void ApproachFlame::execute() {
 delay(500);
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
//End condition for approaching the flame is when the flame is within 10 degrees of center of the robot and within set distance
bool ApproachFlame::isFinished() {
	return (abs(ladder11->flameSense->flameAngle()*180/3.14) < 10) && (ladder11->frontSensor->distance() < 20);
}

void ApproachFlame::end() {
	ladder11->lcd->print("Flame ahead");
	ladder11->drivetrain->stop();
  digitalWrite(32, LOW);
  digitalWrite(34, LOW);
  digitalWrite(46, LOW);
  digitalWrite(48, LOW);
}
