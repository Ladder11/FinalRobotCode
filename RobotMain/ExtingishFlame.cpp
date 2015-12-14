/** 
 * Command to run the motor/fan to extinguish the candle
 * @author Hans Johnson
 * @date Dec. 2015
 **/
#include "ExtingishFlame.h"

ExtingishFlame::ExtingishFlame() : Command("Extingish Flame"){
	ladder11 = Robot::getInstance();
}

/** 
 * Sets up the servo object and arms the ESC
 **/
void ExtingishFlame::initialize() {
	prop.attach(PROP_PIN, 1000, 2000);
	prop.write(180);
    delay(40);
    prop.write(0);
    delay(1000);
    prop.write(180);
}

void ExtingishFlame::execute() {

}
<<<<<<< HEAD
//End condition after 3 seconds of runtime
bool ExtingishFlame::isFinished() {
	return getTime() > 4500;
=======

/**
 * Runs for 3 seconds
 **/ 
bool ExtingishFlame::isFinished() { 
	return getTime() > 3000; //#TODO: Check to make sure the flame is extinguished
>>>>>>> refs/remotes/origin/master
}

/**
 * Turn off the prop
 **/
void ExtingishFlame::end() {
	prop.write(0);
}
