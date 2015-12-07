/** Main file that will be executed on the robot
  * for the RBE2002 Final Project
  * @author Jordan Burklund
  * @author Hans Johnson
  * @author Garrison Hefter
  **/

#include "Robot.h"
#include "Scheduler.h"

Scheduler* scheduler = Scheduler::getInstance();
Robot* ladder11 = Robot:: getInstance();

void setup() {
  ladder11->initializeSubsystems();
}

void loop() {
  scheduler->run();

}
