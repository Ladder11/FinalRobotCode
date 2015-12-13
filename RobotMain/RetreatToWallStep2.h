#ifndef RETREATTOWALLSTEP2
#define RETREATTOWALLSTEP2
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class RetreatToWallStep2 : public Command {
public:
  RetreatToWallStep2(float setpoint);
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  bool isTurning = false;
  long turnStartTime;
  float _setpoint, turnSpeed;
  float distSpeed, moveSpeed;
  double xDelta, yDelta, xDesired, yDesired;
  int thetaDesired, angleDelta;
};



#endif
