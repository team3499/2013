#ifndef FEEDER_H
#define FEEDER_H

#include "Commands/Subsystem.h"
#include "SpeedController.h"
#include "WPILib.h"

/**
 * @author Ethan
 */
class Feeder : public Subsystem
{
public:
    Feeder(int port);

    void InitDefaultCommand();

    void move(float speed);
private:
    SpeedController *motor;
};

#endif // FEEDER_H
