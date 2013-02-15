#include "ShooterWheelUserControl.h"

ShooterWheelUserControl::ShooterWheelUserControl() {
	// Use Requires() here to declare subsystem dependencies
    Requires(shooterWheel);
}

// Called just before this Command runs the first time
void ShooterWheelUserControl::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ShooterWheelUserControl::Execute() {
    bool yes = oi->accessoryPad->GetNumberedButton(1); // xBox 'x' button
    bool no  = oi->accessoryPad->GetNumberedButton(3); // xBox 'b' button

    if(yes && !no){ // if the on button is pressed, but not the off,
        spin = true;
    } else if (!yes && no){ // if the off button is pressed, but not the on.
        spin = false;
    }
    shooterWheel->setSpeed(1.0 * spin);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterWheelUserControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterWheelUserControl::End() {
    shooterWheel->setSpeed(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterWheelUserControl::Interrupted() {
    End();
}
