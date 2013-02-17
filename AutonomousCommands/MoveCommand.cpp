#include "MoveCommand.h"

MoveCommand::MoveCommand(const int direction, double time, float speed) : CommandBase("MoveCommand")
{
    Requires(wheels);
    this->direction = direction; // This can be left and forward (together) as an example.
    this->duration  = time;
    this->speed     = speed;
}

void MoveCommand::Initialize(){
    this->timeStart = Timer::GetPPCTimestamp();

    float fl, fr, rl, rr;

    // Dont know if these have to be cast to a bool, but it wont hurt if they are.

    fr = fl = (bool)(direction & Left) - (bool)(direction & Right);
    rr = rl = -((bool)(direction & Left) - (bool)(direction & Right));

    fr += (bool)(direction & Forward) - (bool)(direction & Reverse);
    fl += (bool)(direction & Forward) - (bool)(direction & Reverse);
    rl += (bool)(direction & Forward) - (bool)(direction & Reverse);
    rr += (bool)(direction & Forward) - (bool)(direction & Reverse);

    if (max(fr, max(fl, max(rr, rl) ) ) > 1.0){
        fl /= max(fr, max(fl, max(rr, rl) ) );
        fr /= max(fr, max(fl, max(rr, rl) ) );
        rl /= max(fr, max(fl, max(rr, rl) ) );
        rr /= max(fr, max(fl, max(rr, rl) ) );
    }

   wheels->Set(fl, fr, rl, rr);
}

void MoveCommand::Execute(){
    ;
}

bool MoveCommand::IsFinished(){
    if(Timer::GetPPCTimestamp() - timeStart > duration)
        return true;
    return false;
}

void MoveCommand::End(){
    wheels->Set(0.0, 0.0, 0.0, 0.0);
}

void MoveCommand::Interrupted(){
    End();
}
