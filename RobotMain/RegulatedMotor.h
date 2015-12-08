#ifndef REGULATEDMOTOR
#define REGULATEDMOTOR
#include <Arduino.h>
#include "KitMotor.h"
#include "KitEncoder.h"
#include "RobotConstants.h"

class RegulatedMotor {
public:
  RegulatedMotor(int motorFPin, int motorRPin, int encoderSS);
  void initialize();
  void setRPM(float rpms);
  float getRPM();
  bool isStalled();
  float getRevolutions();
private:
  KitMotor* _motor;
  KitEncoder* _encoder;
  float avgRPM, newOut, arpm;
  float out = 0.5; //#TODO: Probably not a great idea, need to find a better way to do this
  long lastCount, currentCount;
  unsigned long lastTime, currentTime;
};



#endif