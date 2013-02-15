#include "UserControlPan.h"

UserControlPan::UserControlPan(){
    // Use Requires() here to declare subsystem dependencies
    Requires(pan);
}

// Called just before this Command runs the first time
void UserControlPan::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void UserControlPan::Execute() {
    pan->move(oi->accessoryPad->GetLeftX());
}

// Make this return true when this Command no longer needs to run execute()
bool UserControlPan::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void UserControlPan::End() {
    pan->move(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UserControlPan::Interrupted() {
    End();
}
