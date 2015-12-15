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
	ladder11->telemetry->sendStatus(STATUS_EXT_FLAME, 0);
	prop.attach(PROP_PIN, 1000, 2000);
	prop.write(180);
    delay(40);
    prop.write(0);
    delay(1000);
}

void ExtingishFlame::execute() {
    if (!timedOut) {
         prop.write(180);
    }
    if (getTime() > timeOutTime) { // After the fan has run for the time set
	prop.write(0);
	timedOut = true;
	if (getTime() > (timeOutTime+2000)) { // Give the prop a second to spin down
	    if (ladder11->flameSense->isFlame() && !twitching) { // If there is still a flame, turn the fan back on
		timedOut = false;
		timeOutTime = getTime() + 3000;
	    } else { // If there's not a flame
		if (!twitching) { // If it's not twitching, start twitching
		  twitching = true;
		  twitchingTime = getTime() + 500;
		  prop.write(40);
		} else {
		  prop.write(40);
		  ladder11->lcd->clear();
		  ladder11->lcd->print("Twitching");
		}
		if (getTime() > twitchingTime) { // If it's done twitching
		  twitching = false;
		  prop.write(0); // Turn fan off
		  if (!ladder11->flameSense->isFlame()) { // If there is still no flame after the blade is out of the way, the fire is out 
		    flameOut = true;
		    ladder11->lcd->print("Flame out");
		  } else { // if there is a flame, turn the fan back on
		    timeOutTime = getTime() + 3000;
		    timedOut = false;
		  }
		}
	    }
	}
    }
}

/**
 * Runs for 3 seconds
 **/ 
bool ExtingishFlame::isFinished() { 
	return flameOut;
}

/**
 * Turn off the prop
 **/
void ExtingishFlame::end() {
	prop.write(0);
	ladder11->lights->disableLights();
}
