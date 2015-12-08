#ifndef WALLFOLLOW
#define WALLFOLLOW
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class WallFollow : public Command {
public:
  WallFollow(float setpoint);
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  bool isTurning = false;
  long turnStartTime;
  float _setpoint;
};



#endif
