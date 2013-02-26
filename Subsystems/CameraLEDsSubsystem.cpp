
#include "CameraLEDsSubsystem.h"
#include "../Commands/CameraLEDsBlink.h"
#include "../RobotMap.h"

CameraLEDsSubsystem::CameraLEDsSubsystem() : Subsystem("CameraLEDsSubsystem") {
    greenDO   = new DigitalOutput(CAMERA_GREEN_LEDS_CHANNEL);
    blueDO    = new DigitalOutput(CAMERA_BLUE_LEDS_CHANNEL);
    isGreenOn = false;
    isBlueOn  = false;

    GreenOff();
    BlueOff();
}

void CameraLEDsSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new CameraLEDsBlink);
}

void CameraLEDsSubsystem::GreenOn() {
    greenDO->Set(1);
    isGreenOn = true;
}

void CameraLEDsSubsystem::GreenOff() {
    greenDO->Set(0);
    isGreenOn = false;
}

void CameraLEDsSubsystem::GreenToggle() {
    if (isGreenOn) {
        GreenOff();
    } else {
        GreenOn();
    }
}

bool CameraLEDsSubsystem::IsGreenOn() const {
    return isGreenOn;
}

void CameraLEDsSubsystem::BlueOn() {
    blueDO->Set(1);
    isBlueOn = true;
}

void CameraLEDsSubsystem::BlueOff() {
    blueDO->Set(0);
    isBlueOn = false;
}

void CameraLEDsSubsystem::BlueToggle() {
    if (isBlueOn) {
        BlueOff();
    } else {
        BlueOn();
    }
}

bool CameraLEDsSubsystem::IsBlueOn() const {
    return isBlueOn;
}

