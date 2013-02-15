#include "FeederLaunchOne.h"

FeederLaunchOne::FeederLaunchOne(){
    // Use Requires() here to declare subsystem dependencies
    Requires(feeder);
    SetInterruptible(false);
}

// Called just before this Command runs the first time
void FeederLaunchOne::Initialize() {
    // Start the timer
    // start the motor
}


// Called repeatedly when this Command is scheduled to run
void FeederLaunchOne::Execute() {
    ;
}

// Make this return true when this Command no longer needs to run execute()
bool FeederLaunchOne::IsFinished() {
    // if the timer has gone on long enough, yes
    return false;
}

// Called once after isFinished returns true
void FeederLaunchOne::End() {
    feeder->move(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FeederLaunchOne::Interrupted() {
    End();
}
