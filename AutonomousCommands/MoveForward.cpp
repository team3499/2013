#include "MoveForward.h"

#include "MoveCommand.h"

MoveForward::MoveForward() : CommandGroup("MoveForward"){

    AddSequential(new MoveCommand(/*Direction*/ MoveCommand::Forward, /*time*/ 0.8, /*speed*/ 0.6));

    #warning MoveForward::MoveForward: The time needs to be tested.
}
