#ifndef UPDATETELEMETRY
#define UPDATETELEMETRY
#include <Arduino.h>
#include "RobotConstants.h"
#include "Robot.h"
#include "Command.h"


class PersistentUpdateTelemetry : public Command {
public:
  PersistentUpdateTelemetry();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
};



#endif
