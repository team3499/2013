#ifndef CAMERA_LEDS_BLINK_H
#define CAMERA_LEDS_BLINK_H

#include "CommandBase.h"

class CameraLEDsBlink : public CommandBase {

public:
                             CameraLEDsBlink();

    virtual void             Initialize();
    virtual void             Execute();
    virtual bool             IsFinished();
    virtual void             End();
    virtual void             Interrupted();

private:
    int                      count;
    bool                     greenState;
    bool                     blueState;
    Timer *                  timer;
};

#endif /* CAMERA_LEDS_BLINK_H */
