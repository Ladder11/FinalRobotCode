#include "WaitForStart.h"

WaitForStart::WaitForStart() : Command("Wait For Start"){
  ladder11 = Robot::getInstance();  
}

void WaitForStart::initialize() {
  ladder11->telemetry->sendStatus(STATUS_WAIT4START, 0);
}

void WaitForStart::execute() {

}

bool WaitForStart::isFinished() {
  return ladder11->telemetry->shouldStart();
}

void WaitForStart::end() {

}
