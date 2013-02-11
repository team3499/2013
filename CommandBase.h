#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"

#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/ConfigSubsystem.h"
#include "Subsystems/CameraLEDsSubsystem.h"
#include "Subsystems/Wheels.h"

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
    static CameraLEDsSubsystem * cameraLEDsSubsystem;
    static OI *                  oi;

};

#endif /* COMMAND_BASE_H */
