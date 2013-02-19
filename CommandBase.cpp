#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Robotmap.h"  // Need to include for the port defines

CommandBase::CommandBase(const char *name) : Command(name) {

}

CommandBase::CommandBase() : Command() {

}

// Initialize a single static instance of all of your subsystems to NULL
ConfigSubsystem *      CommandBase::configSubsystem      = NULL;
CameraSubsystem *      CommandBase::cameraSubsystem      = NULL;
CameraLEDsSubsystem *  CommandBase::cameraLEDsSubsystem  = NULL;
Wheels *               CommandBase::wheels               = NULL;
OI *                   CommandBase::oi                   = NULL;
ShooterWheel *         CommandBase::shooterWheel         = NULL;
PanSubsystem *         CommandBase::pan                  = NULL;
TiltSubsystem *        CommandBase::tilt                 = NULL;
Feeder *               CommandBase::feeder               = NULL;
Gyro *                 CommandBase::chassisGyro          = NULL;
Gyro *                 CommandBase::susanGyro            = NULL;

void CommandBase::init() {

    printf("-- CommandBase::init() --\n");

    // Create a single static instance of all of your subsystems. The following
    // line should be repeated for each subsystem in the project.
    wheels              = new Wheels(DRIVE_FRONT_LEFT_CHANNEL, DRIVE_FRONT_RIGHT_CHANNEL,
                                     DRIVE_BACK_LEFT_CHANNEL, DRIVE_BACK_RIGHT_CHANNEL);

    shooterWheel        = new ShooterWheel(THROWER_MOTOR_CHANNEL);
    configSubsystem     = new ConfigSubsystem();
    cameraSubsystem     = new CameraSubsystem();
    cameraLEDsSubsystem = new CameraLEDsSubsystem();
    pan                 = new PanSubsystem(TURNER_MOTOR_CHANNEL);
    tilt                = new TiltSubsystem(TILTER_MOTOR_CHANNEL);
    feeder              = new Feeder(FEEDER_MOTOR_CHANNEL);
    chassisGyro         = new Gyro(CHASSIS_GYRO_CHANNEL); // Analog 1
    susanGyro           = new Gyro(SUSAN_GYRO_CHANNEL);   // Analog 2
    oi                  = new OI();
}
