#include "UserControlFeeder.h"
#include "FeederLaunchOne.h"

UserControlFeeder::UserControlFeeder(){
    // Use Requires() here to declare subsystem dependencies
    Requires(feeder);
}

// Called just before this Command runs the first time
void UserControlFeeder::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void UserControlFeeder::Execute() {
    if(oi->accessoryPad->GetNumberedButton(8)){ // right bumper/trigger
        CommandBase *b = new FeederLaunchOne();
        b->Run();
    }
//    feeder->move(oi->accessoryPad->GetLeftX());
}

// Make this return true when this Command no longer needs to run execute()
bool UserControlFeeder::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void UserControlFeeder::End() {
//    pan->move(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UserControlFeeder::Interrupted() {
    End();
}
