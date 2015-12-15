#ifndef UPDATEDRIVE
#define UPDATEDRIVE
#include <Arduino.h>
#include "RobotConstants.h"
#include "Robot.h"
#include "Command.h"


class PersistentUpdateDrive : public Command {
public:
  PersistentUpdateDrive();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  long triggerTime;
};



#endif
