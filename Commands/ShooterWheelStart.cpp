#include "ShooterWheelStart.h"

ShooterWheelStart::ShooterWheelStart() {
    // Use Requires() here to declare subsystem dependencies
    Requires(shooterWheel);
}

// Called just before this Command runs the first time
void ShooterWheelStart::Initialize() {
    shooterWheel->setSpeed(1.0);
}

// Called repeatedly when this Command is scheduled to run
void ShooterWheelStart::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterWheelStart::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void ShooterWheelStart::End() {
    // Dont do anything.
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterWheelStart::Interrupted() {
    End();
}
