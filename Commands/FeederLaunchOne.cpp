#include "FeederLaunchOne.h"

FeederLaunchOne::FeederLaunchOne(){
    // Use Requires() here to declare subsystem dependencies
    Requires(feeder);
    SetInterruptible(false);
}

// Called just before this Command runs the first time
void FeederLaunchOne::Initialize() {
    time = Timer::GetPPCTimestamp();
    feeder->move(1.0);
}


// Called repeatedly when this Command is scheduled to run
void FeederLaunchOne::Execute() {
    ;
}

// Make this return true when this Command no longer needs to run execute()
bool FeederLaunchOne::IsFinished() {
    if(Timer::GetPPCTimestamp() - time >= 0.695) // If the time is at that of one revolution, exit
        return true;
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
