#include "Commands/CameraLEDsBlink.h"

CameraLEDsBlink::CameraLEDsBlink() {
    Requires(cameraLEDsSubsystem);

    count      = 0;
    greenState = false;
    blueState  = false;

    timer      = new Timer();
}

void CameraLEDsBlink::Initialize() {
    greenState = cameraLEDsSubsystem->IsGreenOn();
    blueState  = cameraLEDsSubsystem->IsBlueOn();
    cameraLEDsSubsystem->GreenOn();
    cameraLEDsSubsystem->BlueOff();
    timer->Reset();
    timer->Start();
    count = 0;
}

void CameraLEDsBlink::Execute() {
    if (timer->HasPeriodPassed(0.500)) {
        cameraLEDsSubsystem->GreenToggle();
        cameraLEDsSubsystem->BlueToggle();
        count++;
    }
}

bool CameraLEDsBlink::IsFinished() {
    return false;
}

void CameraLEDsBlink::End() {
    if (greenState) { cameraLEDsSubsystem->GreenOn(); }
    else { cameraLEDsSubsystem->GreenOff(); }
    if (blueState) { cameraLEDsSubsystem->BlueOn(); }
    else { cameraLEDsSubsystem->BlueOff(); }
}

void CameraLEDsBlink::Interrupted() {
    End();
}
