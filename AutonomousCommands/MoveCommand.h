#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "../CommandBase.h"

class MoveCommand : public CommandBase
{
public:
    MoveCommand(const int direction, double time, float speed = 0.5);
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();

    static const int Left     = 0x0001;
    static const int Right    = 0x0002;
    static const int Forward  = 0x0004;
    static const int Reverse  = 0x0008;

    int    direction;
    float  speed;

    double duration;
    double timeStart;
};

#endif // MOVECOMMAND_H
