#ifndef SHOOTER_WHEEL_START_H
#define SHOOTER_WHEEL_START_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class ShooterWheelStart: public CommandBase {
public:
    ShooterWheelStart();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
