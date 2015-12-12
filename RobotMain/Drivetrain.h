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
  double getcandleFoundX();
  double getcandleFoundY();
  void setCandleFoundY(double loc);
  void setCandleFoundX(double loc);
private:
  float V_r, V_l, prevVel, currAngle, currLeft, currRight, prevLeft, prevRight, leftDelta, rightDelta, robotDelta;
  double xPos, yPos, _theta, candleFoundX, candleFoundY;
  RegulatedMotor* leftMotor;
  RegulatedMotor* rightMotor;
};



#endif
