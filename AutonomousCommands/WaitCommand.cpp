#include "WaitCommand.h"

Wait2Command::Wait2Command(double duration): CommandBase("Wait2Command"){
    // Use Requires() here to declare subsystem dependencies
    this->duration = duration;
    SetInterruptible(false);
}

// Called just before this Command runs the first time
void Wait2Command::Initialize() {
    time = Timer::GetPPCTimestamp();
}


// Called repeatedly when this Command is scheduled to run
void Wait2Command::Execute() {
    ;
}

// Make this return true when this Command no longer needs to run execute()
bool Wait2Command::IsFinished() {
    if(Timer::GetPPCTimestamp() - time >= duration) // If the time is at that of one revolution, exit
        return true;
    return false;
}

// Called once after isFinished returns true
void Wait2Command::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Wait2Command::Interrupted() {
    End();
}
