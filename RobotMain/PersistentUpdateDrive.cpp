/** 
 * Command that continually updates the robot's odometry position
 * @author Hans Johnson
 * @date Dec. 2015
 **/

#include "PersistentUpdateDrive.h"

PersistentUpdateDrive::PersistentUpdateDrive() : Command("Persistent Blink"){
	ladder11 = Robot::getInstance();
}

void PersistentUpdateDrive::initialize() {
	triggerTime = 0;	
}

/** 
 * Blinks the LED strip if it is supposed to, just the yellow turn signals otherwise
 **/
void PersistentUpdateDrive::execute() {
	ladder11->drivetrain->updateRobotPos();
	if (getTime() > triggerTime) {
		ladder11->telemetry->sendRobotPose(ladder11->drivetrain->getXOdoEst(), ladder11->drivetrain->getYOdoEst(), ladder11->drivetrain->getOrientOdoEst());
		triggerTime = getTime() + 500;
	}
}

/**
 * Never ends
 **/
bool PersistentUpdateDrive::isFinished() {
	return false;
}

void PersistentUpdateDrive::end() {

}
