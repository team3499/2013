#include "MoveForward.h"

#include "MoveCommand.h"

MoveForward::MoveForward(int position) : CommandGroup("MoveForward"){

    if(position == 0 || position == 3) // These positions are not to be used with this command.
        return;

    AddSequential(new MoveCommand(/*Direction*/ MoveCommand::Forward, /*time*/ 0.8, /*speed*/ 0.6));

    #warning MoveForward::MoveForward: The time needs to be tested.
}
