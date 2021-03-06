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
#include "ultrasonic.h"
#include "FlameSense.h"
#include <LiquidCrystal.h>
#include "BlinkyLights.h"
#include "Ladder11Telemetry.h"
#include "Gyro.h"

class Robot {
public:
  static Robot* getInstance();
  Drivetrain* drivetrain = new Drivetrain();
  ultrasonic* leftSensor = new ultrasonic(US_LEFT_INPUT_PIN, US_LEFT_OUTPUT_PIN);
  ultrasonic* rightSensor = new ultrasonic(US_RIGHT_INPUT_PIN, US_RIGHT_OUTPUT_PIN);
  ultrasonic* frontSensor = new ultrasonic(US_FRONT_INPUT_PIN, US_FRONT_OUTPUT_PIN);
  FlameSense* flameSense = new FlameSense(40, 30);
  BlinkyLights* lights = new BlinkyLights();
  Ladder11Telemetry* telemetry = new Ladder11Telemetry();
  LiquidCrystal* lcd = new LiquidCrystal(40, 41, 42, 43, 44, 45);
  Gyro* gyro = new Gyro();

  void initializeSubsystems();

private:
  //Private Constructor for singleton
  Robot();
  static Robot* instance;
};


#endif
