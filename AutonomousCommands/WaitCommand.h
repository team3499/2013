#ifndef Wait2Command_H
#define Wait2Command_H

#include "../CommandBase.h"
#include "Timer.h"

/**
 * @author Ethan
 */
class Wait2Command: public CommandBase {
public:
    Wait2Command(double duration);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
private:
    double time;
    double duration;
};

#endif // Wait2Command_H
