#ifndef ROBOT_H
#define ROBOT_H

/**
 * Singleton Robot object for accessing various
 * Robot subsystems
 * @author Jordan Burklund
**/
#include "RobotConstants.h"
#include "Arduino.h"
#include "RegulatedMotor.h"
#include "Drivetrain.h"

class Robot {
public:
  static Robot* getInstance();
  RegulatedMotor* leftRegMotor;
  RegulatedMotor* rightRegMotor;
  Drivetrain* drivetrain;
  void initializeSubsystems();

private:
  //Private Constructor for singleton
  Robot();
  static Robot* instance;
};


#endif
