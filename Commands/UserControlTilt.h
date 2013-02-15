#ifndef USERCONTROLTILT_H
#define USERCONTROLTILT_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class UserControlTilt: public CommandBase {
public:
    UserControlTilt();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // USERCONTROLTILT_H
