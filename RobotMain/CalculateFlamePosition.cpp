#include "CalculateFlamePosition.h"

CalculateFlamePosition::CalculateFlamePosition() : Command("Calculate Flame Position"){
	ladder11 = Robot::getInstance();
}

void CalculateFlamePosition::initialize() {
	flameDistance = ladder11->frontSensor->distance();
	candleXPos = ladder11->drivetrain->getXOdoEst() + sin(ladder11->drivetrain->getOrientOdoEst())*(flameDistance+6.5);
	candleYPos = ladder11->drivetrain->getYOdoEst() + cos(ladder11->drivetrain->getOrientOdoEst())*(flameDistance+6.5);
	candleZPos = 8.0+ladder11->flameSense->flameHeightSin()*flameDistance;

}

void CalculateFlamePosition::execute() {

}

bool CalculateFlamePosition::isFinished() {
	return true;
}

void CalculateFlamePosition::end() {
	ladder11->lcd->clear();
	ladder11->lcd->setCursor(0, 0);
	ladder11->lcd->print("X: ");
	ladder11->lcd->print(candleXPos, DEC);
	ladder11->lcd->setCursor(8, 0);
	ladder11->lcd->print(" Y: ");
	ladder11->lcd->print(candleYPos, DEC);
	ladder11->lcd->setCursor(0, 1);
	ladder11->lcd->print("Z: ");
	ladder11->lcd->print(candleZPos, DEC);
}