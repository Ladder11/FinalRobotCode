#include "ExtingishFlame.h"

ExtingishFlame::ExtingishFlame() : Command("Extingish Flame"){
	ladder11 = Robot::getInstance();
}

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
//End condition after 3 seconds of runtime
bool ExtingishFlame::isFinished() {
	return getTime() > 3000;
}

void ExtingishFlame::end() {
	//ladder11->lcd->clear();
	//ladder11->lcd->print("DONE");
	prop.write(0);
}
