/**
 * Command that calculates the position of the candle relative to the robot's starting location
 * @author Hans Johnson
 * @date Dec. 2015
 **/
#include "CalculateFlamePosition.h"

CalculateFlamePosition::CalculateFlamePosition() : Command("Calculate Flame Position"){
	ladder11 = Robot::getInstance();
}
<<<<<<< HEAD
//Does the trig/math for calculating the position of the flame
//Takes our current robot position and adds relative position of the candle
=======

/** 
 * Does all the calculation, using drivetrain odometry, flame sensor data, and ultrasonic distance to candle
 **/
>>>>>>> refs/remotes/origin/master
void CalculateFlamePosition::initialize() {
	flameDistance = ladder11->frontSensor->distance();
	candleXPos = ladder11->drivetrain->getXOdoEst() + sin(ladder11->drivetrain->getOrientOdoEst())*(flameDistance+6.5);
	candleYPos = ladder11->drivetrain->getYOdoEst() + cos(ladder11->drivetrain->getOrientOdoEst())*(flameDistance+6.5);
	candleZPos = 8.0+ladder11->flameSense->flameHeightSin()*flameDistance;

}

void CalculateFlamePosition::execute() {

}

/** 
 * Only executes once
 */
bool CalculateFlamePosition::isFinished() {
	return true;
}

/**
 * Prints all data to the LCD screen
 **/
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
