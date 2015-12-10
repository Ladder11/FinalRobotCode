#ifndef CALCFLAME
#define CALCFLAME
#include <Arduino.h>
#include "Robot.h"
#include "Command.h"


class CalculateFlamePosition : public Command {
public:
  CalculateFlamePosition();
  void initialize();
  void execute();
  bool isFinished();
  void end();
private:
  Robot* ladder11;
  float flameDistance;
  double height, candleXPos, candleYPos, candleZPos;
};



#endif
