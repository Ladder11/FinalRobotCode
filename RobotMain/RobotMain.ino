#include <PVision.h>






#include <SPI.h>

/** Main file that will be executed on the robot
  * for the RBE2002 Final Project
  * @author Jordan Burklund
  * @author Hans Johnson
  * @author Garrison Hefter
  **/

#include "Robot.h"
#include "Scheduler.h"
#include "Drivetrain.h"
#include "WallFollow.h"
#include "ApproachFlame.h"
#include "ExtingishFlame.h"
#include "WallFollowToStart.h"
#include "CalculateFlamePosition.h"
#include "RetreatToWall.h"

Scheduler* scheduler = Scheduler::getInstance();
Robot* ladder11 = Robot::getInstance();

void setup() {
  ladder11->initializeSubsystems();
  scheduler->addCommand(new WallFollow(8.0));
   
  scheduler->addCommand(new ApproachFlame());
  scheduler->addCommand(new CalculateFlamePosition());
  scheduler->addCommand(new ExtingishFlame());
  scheduler->addCommand(new RetreatToWall(8.0));
  //scheduler->addCommand(new WallFollowToStart(8.0));
}

void loop() {
  scheduler->run();

}
