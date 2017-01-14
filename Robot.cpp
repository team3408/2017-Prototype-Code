#include "WPILib.h"
#include <"CANTalon.h">

class Robot: public IterativeRobot
{
private:

	void RobotInit()
	{
		RobotDrive *theDrive;
		Joystick *leftDriverStick, *rightDriverStick;
		CANTalon *frontLeft,*frontRight, *backRight ,*backLeft, ;
		frontLeft = CANTalonSRX(2);
		frontRight = CANTalonSRX(1);
		backLeft = CANTalonSRX(3);
		backRight = CANTalonSRX(4);
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
