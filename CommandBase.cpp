#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Robotmap.h"  // Need to include for the drive wheel defines

CommandBase::CommandBase(const char *name) : Command(name) {

}

CommandBase::CommandBase() : Command() {

}

// Initialize a single static instance of all of your subsystems to NULL
ConfigSubsystem *      CommandBase::configSubsystem      = NULL;
CameraLEDsSubsystem *  CommandBase::cameraLEDsSubsystem  = NULL;
Wheels *               CommandBase::wheels               = NULL;
OI *                   CommandBase::oi                   = NULL;
ShooterWheel *         CommandBase::shooterWheel         = NULL;
PanSubsystem *         CommandBase::pan                  = NULL;
TiltSubsystem *        CommandBase::tilt                 = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
    // line should be repeated for each subsystem in the project.
	wheels              = new Wheels(DRIVE_FRONT_LEFT_CHANNEL, DRIVE_FRONT_RIGHT_CHANNEL,
                                     DRIVE_BACK_LEFT_CHANNEL, DRIVE_BACK_RIGHT_CHANNEL);

    shooterWheel        = new ShooterWheel(THROWER_MOTOR_CHANNEL);
    configSubsystem     = new ConfigSubsystem();
    cameraLEDsSubsystem = new CameraLEDsSubsystem();
    pan                 = new PanSubsystem(TURNER_MOTOR_CHANNEL);
    tilt                = new TiltSubsystem(TILTER_MOTOR_CHANNEL);
    oi                  = new OI();
}
