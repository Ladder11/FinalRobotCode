#ifndef COMMAND_H
#define COMMAND_H

#include <Arduino.h>

class Command {
	friend class PausableCommand;
public:
	/* Constructors */
	Command();
	Command(const String name);

	String name;

	/* Timeout related */
	void setTimeout(unsigned long timeout);
	virtual unsigned long getTime();
	bool isTimedOut();

	/* Code to execute once on first iteration
	 * Typically overridden by the user */
	virtual void initialize() = 0;
	virtual void _initialize();

	/* Code to execute every iteration 
	 * Typically overridden by the user */
	virtual void execute() = 0;
	virtual void _execute();

	/* Code to check if the command is finished */
	virtual bool isFinished() = 0;

	/* Checks if the command is running */
	bool isRunning();

	/* Code to run once after isFinished is false */
	virtual void end() = 0;
	virtual void _end();

	/* Execute an iteration */
	virtual bool cycle();

	/* Schedule the command */
	void start();

	/* Set if the command should run in parallel */
	void setParallel(bool value);

	/* Check the parallel flag */
	bool isParallel();



private:
	bool initialized, running, parallel;
	unsigned long startTime;	//In msec
	unsigned long timeout;		//In msec
};

#endif
