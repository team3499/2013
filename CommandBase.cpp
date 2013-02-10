#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {

}

CommandBase::CommandBase() : Command() {

}

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem *     CommandBase::examplesubsystem     = NULL;
ConfigSubsystem *      CommandBase::configSubsystem      = NULL;
CameraLEDsSubsystem *  CommandBase::cameraLEDsSubsystem  = NULL;
OI *                   CommandBase::oi                   = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
    // line should be repeated for each subsystem in the project.
    examplesubsystem    = new ExampleSubsystem();
    configSubsystem     = new ConfigSubsystem();
    cameraLEDsSubsystem = new CameraLEDsSubsystem();
    oi                  = new OI();
}
