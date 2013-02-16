#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "AutonomousCommands/AutonomousCommand.h"

class Team3499Robot : public IterativeRobot {
private:
	Command *autonomousCommand;
    LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
        autonomousCommand = new AutonomousCommand((unsigned char)'\12');
        lw = LiveWindow::GetInstance();
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

