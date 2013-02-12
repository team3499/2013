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
	shooterWheel->set(oi->accessoryPad->getLeftX()); // This also allows for the D-pad to be in controll, allowing for 100%-itiy
#warning This is only the controls for testing.
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterWheelUserControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterWheelUserControl::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterWheelUserControl::Interrupted() {
}
