#ifndef EXTINGUISHFLAME
#define EXTINGUISHFLAME
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"
#include <Servo.h>


class ExtingishFlame : public Command {
public:
  ExtingishFlame();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  Servo prop;
};



#endif
