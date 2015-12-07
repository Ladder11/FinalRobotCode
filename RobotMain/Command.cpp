/** Commands encapsulate functionality of a task to execute
  * iteratively with a timeout.
  * Code is mostly copied from WPILib, and adapted/stripped
  * down to work on the Arduino
  * credits to PeterMitrano for some of the initial code
  * @author Jordan Burkllund
  * @date Sept. 2015
  **/

#include "Command.h"
#include "Scheduler.h"

/** Generic Constructor **/
Command::Command() : initialized(false), parallel(false)
{}

/** Constructor that specifies a name for the command
  * @param name Name of the command
  **/
Command::Command(String name) : initialized(false), name(name), parallel(false)
{}

/** Sets the timeout period of the command
  * @param timeout Timeout in milliseconds
  **/
void Command::setTimeout(unsigned long timeout) {
	this->timeout = timeout;
}

/** Get the time from the start of the command
  * @return time since the command has started in milliseconds
  **/
unsigned long Command::getTime() {
	return millis() - this->startTime;
}

/** Check if the command has timed out
  * @return True if the command has timed out
  **/
bool Command::isTimedOut() {
	return getTime() > timeout;
}

/** Checks if the command is currently running
  * @return True if the command is currently running
  **/
bool Command::isRunning() {
	return running;
}

/** Schedule the command to start executing **/
void Command::start() {
	Scheduler::getInstance()->addCommand(this);
}

/** Background code for initialization **/
void Command::_initialize() {
	running = true;
	startTime = millis();
}

/** Background code for executing **/
void Command::_execute() {
}

/** Background code for ending **/
void Command::_end() {
	running = false;
}

/** Execute an iteration of the command 
  * @return True if the command is finished
  **/
bool Command::cycle() {
	bool finished = false;

	if(!initialized) {
		//Initialize the command if it hasn't been already
		initialize();
		_initialize();
		initialized = true;
	} else if (isFinished()) {
		//Call the end method when the command is done
		finished = true;
		end();
		_end();
	} else {
		//Otherwise execute one iteration of the command
		execute();
		_execute();
	}

	return finished;
}

/** Set the flag to run in parallel, or
  * run sequentially
  * @param value If true: parallel, if false: sequential
  **/ 
void Command::setParallel(bool value) {
	parallel = value;
}

/** Check if the flag is set to run this command
  * in parallel
  * @return True if the command should run in parallel
  **/
bool Command::isParallel() {
	return parallel;
}