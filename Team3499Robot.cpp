#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/CameraLEDsBlink.h"
#include "AutonomousCommands/AutonomousCommand.h"
#include "CommandBase.h"

class Team3499Robot : public IterativeRobot {
private:
    Command * autonomousCommand;
    Command * blinkCommand;
    Command * cameraTestCommand;
    LiveWindow *lw;

    virtual void RobotInit() {
        CommandBase::init();
        autonomousCommand = new AutonomousCommand(0x0C);
        blinkCommand      = new CameraLEDsBlink();
        lw = LiveWindow::GetInstance();

        CommandBase::cameraLEDsSubsystem->GreenOff();
        CommandBase::cameraLEDsSubsystem->BlueOff();
    }

    virtual void DisabledInit() {
        CommandBase::cameraLEDsSubsystem->GreenOff();
        CommandBase::cameraLEDsSubsystem->BlueOff();
    }

    virtual void DisabledPeriodic() {

    }

    virtual void AutonomousInit() {
        autonomousCommand->Start();
    }

    virtual void AutonomousPeriodic() {
        Scheduler::GetInstance()->Run();
    }

    virtual void TeleopInit() {
        // This makes sure that the autonomous stops running when
        // teleop starts running. If you want the autonomous to
        // continue until interrupted by another command, remove
        // this line or comment it out.

        autonomousCommand->Cancel();
        printf("\n--            --\n");
        printf("-- Teleop Hit --\n");
        printf("--            --\n\n");
    }

    virtual void TeleopPeriodic() {
        Scheduler::GetInstance()->Run();
    }

    virtual void TestPeriodic() {
        lw->Run();
    }
};

START_ROBOT_CLASS(Team3499Robot);

