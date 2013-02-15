#include "TiltSubsystem.h"

#include "Victor.h"

#include "../Commands/UserControlTilt.h"

TiltSubsystem::TiltSubsystem(int port) : Subsystem("TiltSubsystem"){
    motor = new Victor(port);
}

void TiltSubsystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new UserControlTilt());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void TiltSubsystem::move(float speed){
    motor->Set(speed);
}

