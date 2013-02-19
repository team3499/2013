#ifndef CAMERA_TEST_H
#define CAMERA_TEST_H

#include "CommandBase.h"

class CameraTest : public CommandBase {

public:
                             CameraTest();

    virtual void             Initialize();
    virtual void             Execute();
    virtual bool             IsFinished();
    virtual void             End();
    virtual void             Interrupted();

private:
    Timer *                  timer;

    bool                     finished;
    bool                     greenOn;
    bool                     blueOn;
};

#endif /* CAMERA_TEST_H */
