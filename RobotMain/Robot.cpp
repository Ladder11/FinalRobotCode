/** Singleton instance of the robot that contains all of the
  * references to the robot subystems, and provides methods
  * for initializing the robot.
  * @author Jordan Burklund
  * @date Dec. 2015
  **/

#include "Robot.h"

Robot* Robot::instance = NULL;

/* Priate Constructor */
Robot::Robot() {}

/** Gets a reference to the Singleon instance of this robot
  * @return Pointer to the Robot object
  **/
Robot* Robot::getInstance() {
  if(instance == NULL) {
    instance = new Robot();
  }
  return instance;
}

/** Calls initialize methods for all subsystems
  **/
void Robot::initializeSubsystems() {
  drivetrain->initialize();
  flameSense->initialize();
  lcd->begin(16, 2);
}
