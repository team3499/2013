#include "AutonomousCommand.h"

#include "MoveForward.h"
#include "MoveToSide.h"
#include "../Commands/FeederLaunchOne.h"
#include "../Commands/ShooterWheelStart.h"
#include "../Commands/ShooterWheelStop.h"
#include "Commands/WaitCommand.h"
#include "MoveCommand.h" // For the const defines.
// #include "../Commands/Aim.h"

AutonomousCommand::AutonomousCommand(unsigned char bits) : CommandGroup("AutonomousCommand"){
            // bits are from the configSubsystem.
    bits;

    // Determine position:
    unsigned char position = bits & 0x03;

    // Determine what to do with it:
    unsigned char commands = bits & 0x00C;

    commands >>= 2;
#warning Forcing to pick option 3
    commands = 3;
    switch(commands){
    case 0: // Use will all positions.
            // Shoot at open target.
        // if position 0 or 3, aim (and tilt) for 3 pointer.
        // if position 1 or 2, aim (and tilt) for the 2 pointer on that side.
        AddSequential(new ShooterWheelStart());
        AddSequential(new WaitCommand(6.0));
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new ShooterWheelStop());
        break;
    case 1: // Use with rear (1 and 2)
            // Move sideways, aim, fire.
        // based on side, go out that direction.
        // maybe aim a little so its a 'gaurentee' to have the target in our cameras view.
        // Aim
        AddSequential(new ShooterWheelStart());
        AddSequential(new WaitCommand(6.0));
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new ShooterWheelStop());
        break;
    case 2: // Use with rear (1 and 2)
            // Move sidways, forwards, aim, fire.
        // based on side, go out that direction.
        // go forward
        // maybe aim a little so its a 'gaurentee' to have the target in our cameras view.
        // aim.
        AddSequential(new ShooterWheelStart());
        AddSequential(new WaitCommand(6.0));
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new ShooterWheelStop());
        break;
    case 3: // Use with all.
            // Just shoot the frisbees.
        AddSequential(new ShooterWheelStart());
        AddSequential(new WaitCommand(6.0));
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new FeederLaunchOne());
        AddSequential(new ShooterWheelStop());
        break;
    default:
        ; //Error!
        break;
    }


    //& MoveCommand::Left;
}

#warning take away the middle-man commands.
