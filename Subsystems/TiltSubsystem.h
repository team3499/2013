#ifndef TILTSUBSYSTEM_H
#define TILTSUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "SpeedController.h"
#include "WPILib.h"

/**
 * @author Ethan
 */
class TiltSubsystem : public Subsystem
{
public:
    TiltSubsystem(int port);
    void InitDefaultCommand();

    void move(float speed);
private:
    SpeedController *motor;
};


#endif // TILTSUBSYSTEM_H
