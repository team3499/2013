#include "UserControlTilt.h"

UserControlTilt::UserControlTilt(){
    // Use Requires() here to declare subsystem dependencies
    Requires(tilt);
}

// Called just before this Command runs the first time
void UserControlTilt::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void UserControlTilt::Execute() {
    tilt->move(oi->accessoryPad->GetLeftY());
}

// Make this return true when this Command no longer needs to run execute()
bool UserControlTilt::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void UserControlTilt::End() {
    tilt->move(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UserControlTilt::Interrupted() {
    End();
}
