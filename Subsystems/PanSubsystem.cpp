#include "PanSubsystem.h"

#include "Victor.h"

#include "../Commands/UserControlPan.h"

PanSubsystem::PanSubsystem(int port) : Subsystem("PanSubsystem"){
    motor = new Victor(port);
}

void PanSubsystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new UserControlPan());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void PanSubsystem::move(float speed){
    motor->Set(speed);
}

