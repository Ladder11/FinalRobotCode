#ifndef APPROACHFLAME
#define APPROACHFLAME
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class ApproachFlame : public Command {
public:
  ApproachFlame();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  float distSpeed;
};



#endif
