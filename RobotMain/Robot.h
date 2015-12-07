#ifndef ROBOT_H
#define ROBOT_H

/**
 * Singleton Robot object for accessing various
 * Robot subsystems
 * @author Jordan Burklund
**/
#include "RobotConstants.h"
#include "Arduino.h"

class Robot {
public:
  static Robot* getInstance();
  void initializeSubsystems();

private:
  //Private Constructor for singleton
  Robot();
  static Robot* instance;
};


#endif
