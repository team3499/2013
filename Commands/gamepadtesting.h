#ifndef GAMEPADTESTING_H
#define GAMEPADTESTING_H

#include "../CommandBase.h"

/**
 * @author Ethan
 */
class GamepadTesting : public CommandBase
{
public:
    GamepadTesting();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif // GAMEPADTESTING_H
