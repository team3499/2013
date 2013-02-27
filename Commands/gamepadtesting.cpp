#include "gamepadtesting.h"

void drawJS(float value){
    if(value > .8){
        printf("(----|)");
    } else if(value < -.8){
        printf("(|----)");
    } else if(value > .2){
        printf("(---|-)");
    } else if(value < -.2){
        printf("(-|---)");
    } else {
        printf("(--|--)");
    }
}

GamepadTesting::GamepadTesting()
{
}

// Called just before this Command runs the first time
void GamepadTesting::Initialize() {
    printf("Initializing gamepadTesting\n");
}

// Called repeatedly when this Command is scheduled to run
void GamepadTesting::Execute() {
    printf("DriveJS:                                             AccessoryJS:\n");
    printf("Left: x:");
    drawJS(oi->drivePad->GetLeftX());
    printf("y:");
    drawJS(oi->drivePad->GetLeftY());
    printf(" Right: x:");
    drawJS(oi->drivePad->GetRightX());
    printf(" y:");
    drawJS(oi->drivePad->GetRightY());
    printf(" Left: x:");
    drawJS(oi->accessoryPad->GetLeftX());
    printf(" y:");
    drawJS(oi->accessoryPad->GetLeftY());
    printf(" Right: x:");
    drawJS(oi->accessoryPad->GetRightX());
    printf(" y:");
    drawJS(oi->accessoryPad->GetRightY());
    printf("\n");

    /*

DriveJS:                                             AccessoryJS:
Left: x:(--|--) y:(--|--) Right: x:(--|--) y:(--|--) Left: x:(--|--) y:(--|--) Right: x:(--|--) y:(--|--)





      */
}

// Make this return true when this Command no longer needs to run execute()
bool GamepadTesting::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void GamepadTesting::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GamepadTesting::Interrupted() {
}
