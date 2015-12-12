#ifndef RETREATTOWALL
#define RETREATTOWALL
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class RetreatToWall : public Command {
public:
  RetreatToWall(float setpoint);
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  bool isTurning = false;
  long turnStartTime;
  float _setpoint, turnSpeed;
  float distSpeed, xDelta, yDelta, thetaDesired;
};



#endif
