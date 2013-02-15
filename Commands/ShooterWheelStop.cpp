#include "ShooterWheelStop.h"

ShooterWheelStop::ShooterWheelStop() {
    // Use Requires() here to declare subsystem dependencies
    Requires(shooterWheel);
}

// Called just before this Command runs the first time
void ShooterWheelStop::Initialize() {
    shooterWheel->setSpeed(0.0);
}

// Called repeatedly when this Command is scheduled to run
void ShooterWheelStop::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterWheelStop::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void ShooterWheelStop::End() {
    // Dont do anything.
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterWheelStop::Interrupted() {
    End();
}
