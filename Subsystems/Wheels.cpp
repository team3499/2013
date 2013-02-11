#include "Wheels.h"
#include "../Robotmap.h"
#include "Victor.h"
#include "SpeedController.h"
#include "../Commands/MecanumnDrive.h"

Wheels::Wheels(int frontLeft, int frontRight,
	       int rearLeft, int rearRight): Subsystem("Wheels") {
    this->frontLeftMotor  = new Victor(frontLeft);
    this->frontRightMotor = new Victor(frontRight);
    this->rearLeftMotor   = new Victor(rearLeft);
    this->rearRightMotor  = new Victor(rearRight);
}
    
void Wheels::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new MecanumnDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Wheels::Set(float frontLeft, float frontRight,
		         float rearLeft, float rearRight){
	  frontLeftMotor->Set(frontLeft);
	  frontRightMotor->Set(frontRight);
	  rearLeftMotor->Set(rearLeft);
	  rearRightMotor->Set(rearRight);
}
