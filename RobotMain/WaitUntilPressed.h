#ifndef WAITUNTILPRESSED_H
#define WAITUNTILPRESSED_H

#include "Robot.h"
#include "Command.h"

class WaitUntilPressed : public Command {
public:
    WaitUntilPressed();
    void initialize();
    void execute();
    void end();
    bool isFinished();
private:
    Robot* ladder11;
};

#endif

