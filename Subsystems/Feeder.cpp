#include "Feeder.h"
#include "../Commands/UserControlFeeder.h"

#include "Victor.h"

Feeder::Feeder(int port) : Subsystem("Feeder")
{
    motor = new Victor(port);
}

void Feeder::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new UserControlFeeder());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Feeder::move(float speed){
    motor->Set(speed);
}

