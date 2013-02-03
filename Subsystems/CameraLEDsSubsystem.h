#ifndef CAMERA_LEDS_SUBSYSTEM_H
#define CAMERA_LEDS_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CameraLEDsSubsystem : public Subsystem {

public:
                             CameraLEDsSubsystem();

    void                     GreenOn();
    void                     GreenOff();
    void                     GreenToggle();
    bool                     IsGreenOn() const;

    void                     BlueOn();
    void                     BlueOff();
    void                     BlueToggle();
    bool                     IsBlueOn() const;

protected:
    void                     InitDefaultCommand();

private:
    DigitalOutput*           greenDO;
    DigitalOutput*           blueDO;
    bool                     isGreenOn;
    bool                     isBlueOn;
};

#endif /* CAMERA_LEDS_SUBSYSTEM_H */
