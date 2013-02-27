#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Robotmap.h"  // Need to include for the port defines

CommandBase::CommandBase(const char *name) : Command(name) {

}

CommandBase::CommandBase() : Command() {

}

// Initialize a single static instance of all of your subsystems to NULL
OI * CommandBase::oi = NULL;


void CommandBase::init() {

    printf("-- CommandBase::init() --\n");

    // Create a single static instance of all of your subsystems. The following
    // line should be repeated for each subsystem in the project.
    oi = new OI();
    printf("oi = %d", oi);
}
