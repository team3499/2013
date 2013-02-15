#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"

#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/ConfigSubsystem.h"
#include "Subsystems/CameraSubsystem.h"
#include "Subsystems/CameraLEDsSubsystem.h"
#include "Subsystems/Wheels.h"
#include "Subsystems/ShooterWheel.h"
#include "Subsystems/PanSubsystem.h"
#include "Subsystems/TiltSubsystem.h"

#include "OI.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase : public Command {

public:
    CommandBase(const char *name);
    CommandBase();

    static void                  init();

    static Wheels *              wheels;
    static ConfigSubsystem *     configSubsystem;
    static CameraSubsystem *     cameraSubsystem;
    static CameraLEDsSubsystem * cameraLEDsSubsystem;
    static ShooterWheel *        shooterWheel;
    static OI *                  oi;
    static PanSubsystem *        pan;
    static TiltSubsystem *       tilt;

};

#endif /* COMMAND_BASE_H */
