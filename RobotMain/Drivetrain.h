#ifndef DRIVETRAIN
#define DRIVETRAIN
#include <Arduino.h>
#include "RegulatedMotor.h"
#include "RobotConstants.h"

class Drivetrain {
public:
  Drivetrain();
  void initialize();
  void drive(float velocity, float turnVelocity);
  void stop();
  double getXOdoEst();
  double getYOdoEst();
  double getOrientOdoEst();
  void updateRobotPos();
  double getCandleFoundX();
  double getCandleFoundY();
  void setCandleFoundY();
  void setCandleFoundX();
private:
  float V_r, V_l, prevVel, currAngle, currLeft, currRight, prevLeft, prevRight, leftDelta, rightDelta, robotDelta;
  double xPos, yPos, _theta, candleFoundX, candleFoundY;
  RegulatedMotor* leftMotor;
  RegulatedMotor* rightMotor;
};



#endif
