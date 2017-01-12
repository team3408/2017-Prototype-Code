#include "WPILib.h"

class Robot: public IterativeRobot
{
private:

	void RobotInit()
	{
		RobotDrive *theDrive;
		Joystick *left, *right;
		CANTalon *rearLeft, *frontLeft, *rearRight, *frontRight;
		frontLeft = CANTalon(2);
		frontRight = CANTalon(1);
		backLeft = CANTalon(3);
		backRight = CANTalon(4);
	}



	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{
		theDrive = new RobotDrive(frontRight, frontLeft, backLeft, backRight);
		left = new Joystick(1);
		right = new Joystick(2);
	}

	void TeleopPeriodic()
	{
	
		theDrive->TankDrive(left,right);
		
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
