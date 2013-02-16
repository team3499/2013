#ifndef AUTONOMOUS_COMMAND_H
#define AUTONOMOUS_COMMAND_H

#include "Commands/CommandGroup.h"

/**
  * @author Ethan
  */
class AutonomousCommand : public CommandGroup
{
public:
    AutonomousCommand(unsigned char bits);
};

#endif // AUTONOMOUSCOMMAND_H
