#ifndef PANSUBSYSTEM_H
#define PANSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "SpeedController.h"
#include "WPILib.h"

/**
 * @author Ethan
 */
class PanSubsystem : public Subsystem
{
public:
    PanSubsystem(int port);
    void InitDefaultCommand();

    void move(float speed);
private:
    SpeedController *motor;
};

#endif // PANSUBSYSTEM_H
