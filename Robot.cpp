#include "WPILib.h"
#include <"CANTalon.h">

class Robot: public IterativeRobot
{
public:

	void RobotInit()
	{
		RobotDrive *theDrive;
		Joystick *leftDriverStick, *rightDriverStick;
		CANTalon *frontLeft,*frontRight, *backRight ,*backLeft, ;
		frontLeft = new CANTalonSRX(2);
		frontRight = new CANTalonSRX(1);
		backLeft = new CANTalonSRX(3);
		backRight = new CANTalonSRX(4);
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
