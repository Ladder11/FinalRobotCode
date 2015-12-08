#include "CalculateFlamePosition.h"

CalculateFlamePosition::CalculateFlamePosition() : Command("Calculate Flame Position"){
	ladder11 = Robot::getInstance();
}

void CalculateFlamePosition::initialize() {

}

void CalculateFlamePosition::execute() {
	flameDistance = ladder11->frontSensor->distance();
	candleXPos = ladder11->drivetrain->getXOdoEst() + cos(ladder11->drivetrain->getOrientOdoEst())*flameDistance;
	candleYPos = ladder11->drivetrain->getYOdoEst() + sin(ladder11->drivetrain->getOrientOdoEst())*flameDistance;
	candleZPos = ladder11->flameSense->flameHeightSin()*flameDistance+7.5;
}

bool CalculateFlamePosition::isFinished() {

	return true;
}

void CalculateFlamePosition::end() {
	
}