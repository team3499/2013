#ifndef SHOOTER_WHEEL_STOP_H
#define SHOOTER_WHEEL_STOP_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class ShooterWheelStop: public CommandBase {
public:
    ShooterWheelStop();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
