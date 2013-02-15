#ifndef USERCONTROLPAN_H
#define USERCONTROLPAN_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class UserControlPan: public CommandBase {
public:
    UserControlPan();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // USERCONTROLPAN_H
