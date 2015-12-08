#include "ApproachFlame.h"

ApproachFlame::ApproachFlame() : Command("Approach Flame"){
	ladder11 = Robot::getInstance();
}

void ApproachFlame::initialize() {

}

void ApproachFlame::execute() {
	distSpeed = .25*(ladder11->frontSensor->distance()-20);
    if (distSpeed > 5) {
      distSpeed = 5;
    }
    ladder11->drivetrain->drive(distSpeed, ladder11->flameSense->flameAngle()*180/3.1415*4);
}

bool ApproachFlame::isFinished() {
	return (abs(ladder11->flameSense->flameAngle()*180/3.14) < 10) && (ladder11->frontSensor->distance() < 20);
}

void ApproachFlame::end() {
	ladder11->lcd->print("Flame ahead");
	ladder11->drivetrain->stop();
}