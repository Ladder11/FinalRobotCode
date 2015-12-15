#ifndef WAITFORSTART
#define WAITFORSTART
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class WaitForStart : public Command {
public:
  WaitForStart();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
};



#endif
