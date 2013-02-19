#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class MecanumnDrive: public CommandBase {
public:
	MecanumnDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
    bool   lastWasDriveStrait;
    double lastGyroAngle;
};

#endif
