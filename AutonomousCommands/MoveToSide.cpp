#include "MoveToSide.h"

#include "MoveCommand.h"

MoveToSide::MoveToSide(int position) : CommandGroup("MoveToSide"){

    if(position == 0 || position == 3) // These positions are not to be used with this command.
        return;

    else if(position == 1)
        AddSequential(new MoveCommand(/*Direction*/ MoveCommand::Right, /*time*/ 0.8, /*speed*/ 0.6));

    else if(position == 2)
        AddSequential(new MoveCommand(/*Direction*/ MoveCommand::Left, /*time*/ 0.8, /*speed*/ 0.6));

    else
        ; // ERROR!

    #warning MoveToSide::MoveToSide The time needs to be tested.
}
