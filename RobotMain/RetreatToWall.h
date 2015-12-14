#ifndef RETREATTOWALL
#define RETREATTOWALL
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"
#include "math.h"

class RetreatToWall : public Command {
public:
  RetreatToWall();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  bool isTurning = false;
  long turnStartTime;
  float turnSpeed, distSpeed;
  double xDelta, yDelta;
  int thetaDesired, angleDelta;
};



#endif
