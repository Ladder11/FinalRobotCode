/** 
 * Command that recieves messages from the Android app over Bluetooth
 * @author Hans Johnson
 * @date Dec. 2015
 **/

#include "PersistentUpdateTelemetry.h"

PersistentUpdateTelemetry::PersistentUpdateTelemetry() : Command("Persistent Update Telemetry"){
	ladder11 = Robot::getInstance();
}

void PersistentUpdateTelemetry::initialize() {
	
}

/** 
 * Blinks the LED strip if it is supposed to, just the yellow turn signals otherwise
 **/
void PersistentUpdateTelemetry::execute() {
  ladder11->telemetry->readPacket();
}

/**
 * Never ends
 **/
bool PersistentUpdateTelemetry::isFinished() {
	return false;
}

void PersistentUpdateTelemetry::end() {

}
