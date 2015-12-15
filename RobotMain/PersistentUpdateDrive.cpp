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
 * Always updates the robot's position, and sends a pose update every 500ms
 **/
void PersistentUpdateDrive::execute() {
	ladder11->drivetrain->updateRobotPos();
	ladder11->gyro->updateGyro();
	if (getTime() > triggerTime) {
		ladder11->telemetry->sendRobotPose(ladder11->drivetrain->getXOdoEst(), ladder11->drivetrain->getYOdoEst(), ladder11->drivetrain->getOrientOdoEst()*180/3.1415);
		ladder11->telemetry->sendGyroOrientation(ladder11->gyro->getGyro());
		triggerTime = getTime() + 100;
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
