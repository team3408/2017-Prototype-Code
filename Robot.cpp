#include "WPILib.h"
#include <Timer.h>

class Robot: public IterativeRobot
{


private:
	LiveWindow *lw = LiveWindow::GetInstance();
	//SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
	RobotDrive *RoboDrive;
	Joystick *stick1, *stick2;
	Spark *rearLeft, *frontLeft, *rearRight, *frontRight, *shooter, *climber;
	double leftWheels;
	double rightWheels;
	bool spinWheel;
	bool climberSpin;

	//double sparkPower = 0.5;

	Timer *autotimer;
	double stopTime;


	void RobotInit()
	{
		//chooser = new SendableChooser();
		//chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		///chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		//SmartDashboard::PutData("Auto Modes", chooser);

		//Declaring sparks for drive code
		frontLeft = new Spark(0);
		rearLeft = new Spark(1);

		frontRight = new Spark(3);
		rearRight = new Spark(2);

		// Declaring sparks for shooter
		shooter = new Spark(4);

		// Decalaring sparks for climber
		climber = new Spark(5);


		// Declaring controllers
		stick1 = new Joystick(0); // Port zero
		stick2 = new Joystick(1); // Port one

		// Declaring Variables for Autonomous
		autotimer = new Timer();
		stopTime = 5;

		// Inverting motors
		rearLeft->SetInverted(true);
		frontLeft->SetInverted(true);


	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit()
	{
		autotimer->Start();

		/*
		autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}*/
	}

	void AutonomousPeriodic()
	{
		if(autotimer->Get() > 5)
		{
			rearLeft -> Set(0);
			rearRight -> Set(0);
			frontLeft -> Set(0);
			frontRight -> Set(0);
		}

		else
		{
			rearLeft -> Set(0.5);
			rearRight -> Set(0.5);
			frontRight -> Set(0.5);
			frontLeft -> Set(0.5);
		}

		/*
		if(autotimer > stopTime)
		{
			frontRight->Set(0.5);
			frontLeft->Set(0.5);
			rearLeft->Set(0.5);
			rearRight->Set(0.5);
		}

		else
		{
			frontRight->Set(0);
			frontLeft->Set(0);
			rearLeft->Set(0);
			rearRight->Set(0);
		}
		*/

	}

	void TeleopInit()
	{
		//Inverting motors for the left side for forward drive



	}
	void TeleopPeriodic()
	{
		//DRIVE CODE
		leftWheels = stick1 -> GetRawAxis(1); //leftwheels doesnt work
		rightWheels = stick1 -> GetRawAxis(5);
		frontLeft -> Set(leftWheels);
		frontRight -> Set(rightWheels);
		rearLeft -> Set(leftWheels);
		rearRight -> Set(rightWheels);

		//SHOOTER CODE
		spinWheel = stick1 -> GetRawButton(1);
		//shooter -> Set(0.8); //testing shooter

		climberSpin = stick1 -> GetRawButton(2);

		if (spinWheel)
		{
			shooter->Set(-0.8);
		}
		else
		{
			shooter->Set(0);
		}

		if (climberSpin)
		{
			climber->Set(1);
		}
		else
		{
			climber->Set(0);
		}


	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
