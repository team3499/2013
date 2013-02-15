#ifndef FEEDER_LAUNCH_ONE_H
#define FEEDER_LAUNCH_ONE_H

#include "../CommandBase.h"
#include "Timer.h"

/**
 * @author Ethan
 */
class FeederLaunchOne: public CommandBase {
public:
    FeederLaunchOne();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
private:
    Timer *t;
};

#endif // FeederLaunchOne_H
