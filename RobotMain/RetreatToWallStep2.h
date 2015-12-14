#ifndef RETREATTOWALLSTEP2
#define RETREATTOWALLSTEP2
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"
#include "math.h"

class RetreatToWallStep2 : public Command {
public:
  RetreatToWallStep2();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  bool isTurning = false;
  long turnStartTime;
  float turnSpeed, distSpeed, moveSpeed;
  double xDelta, yDelta, xDesired, yDesired;
  int thetaDesired, angleDelta;
};



#endif
