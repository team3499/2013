#include "WPILib.h"
#include "Commands/GamepadTesting.h"
#include "CommandBase.h"

class Team3499Robot : public IterativeRobot {
private:

    Command * gamepadTesting;

    LiveWindow *lw;

    virtual void RobotInit() {
        CommandBase::init();
        lw = LiveWindow::GetInstance();
        gamepadTesting = new GamepadTesting();
    }

    virtual void DisabledInit() {
    }

    virtual void DisabledPeriodic() {

    }

    virtual void AutonomousInit() {
    }

    virtual void AutonomousPeriodic() {
        Scheduler::GetInstance()->Run();
    }

    virtual void TeleopInit() {
        // This makes sure that the autonomous stops running when
        // teleop starts running. If you want the autonomous to
        // continue until interrupted by another command, remove
        // this line or comment it out.
        printf("\n--            --\n");
        printf("-- Teleop Hit --\n");
        printf("--            --\n\n");
        gamepadTesting->Start();
    }

    virtual void TeleopPeriodic() {
        Scheduler::GetInstance()->Run();
    }

    virtual void TestPeriodic() {
        lw->Run();
    }
};

START_ROBOT_CLASS(Team3499Robot);

