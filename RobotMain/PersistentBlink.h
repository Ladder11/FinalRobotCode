#ifndef BLINK
#define BLINK
#include <Arduino.h>
#include "RobotConstants.h"
#include "Robot.h"
#include "Command.h"


class PersistentBlink : public Command {
public:
  PersistentBlink();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
};



#endif
