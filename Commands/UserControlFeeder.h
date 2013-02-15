#ifndef USER_CONTROL_FEEDER_H
#define USER_CONTROL_FEEDER_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class UserControlFeeder: public CommandBase {
public:
    UserControlFeeder();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // UserControlFeeder_H
