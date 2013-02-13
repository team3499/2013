#include "ShooterWheel.h"
#include "../Commands/ShooterWheelUserControl.h"
#include "Jaguar.h"

ShooterWheel::ShooterWheel(int port) : Subsystem("ShooterWheel") {
	speedController = new Jaguar(port);
}
    
void ShooterWheel::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ShooterWheelUserControl());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.


void ShooterWheel::setSpeed(float speed){
    speedController->Set(speed);
}
