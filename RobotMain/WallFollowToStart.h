#ifndef WALLFOLLOWTOSTART
#define WALLFOLLOWTOSTART
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class WallFollowToStart : public Command {
public:
  WallFollowToStart(float setpoint);
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  bool isTurning = false;
  long turnStartTime;
  float _setpoint, turnSpeed;
};



#endif
