#include "WPILib.h"

class Robot: public IterativeRobot
{
private:

	void RobotInit()
	{
		RobotDrive *theDrive;
		Joystick *leftDriverStick, *rightDriverStick;
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
		leftDriverStick = new Joystick(1);
		rightDriverStick = new Joystick(2);
	}

	void TeleopPeriodic()
	{

		theDrive->TankDrive(leftDriverStick,rightDriverStick);
		
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
