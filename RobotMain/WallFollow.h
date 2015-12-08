#ifndef WALLFOLLOW
#define WALLFOLLOW
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class WallFollow : public Command {
public:
  WallFollow(int setpoint);
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  bool isTurning;
  long turnStartTime;
  float _setpoint;
};



#endif
