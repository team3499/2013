#ifndef SHOOTER_WHEEL_USER_CONTROL_H
#define SHOOTER_WHEEL_USER_CONTROL_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class ShooterWheelUserControl: public CommandBase {
public:
    ShooterWheelUserControl();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
    virtual void Interrupted();

private:
    bool spin;
};

#endif
