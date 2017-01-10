#include "WPILib.h"

class Robot: public IterativeRobot
{
private:

	void RobotInit()
	{
		RobotDrive *theDrive;
		Joystick *left, *right;
	}



	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		theDrive = new RobotDrive(0,1,2,3);
		left = new Joystick(1);
		right = new Joystick(2);
	}

	void TeleopPeriodic()
	{
		while(isOperatorControl() && isEnabled())
		{
			theDrive->Tank(left,right);
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
