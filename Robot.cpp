#include "WPILib.h"

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
	Spark *rearLeft, *frontLeft, *rearRight, *frontRight, *shooter;
	double leftWheels;
	double rightWheels;
	bool spinWheel;
	double sparkPower = 0.5;


	void RobotInit()
	{
		//chooser = new SendableChooser();
		//chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		///chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		//SmartDashboard::PutData("Auto Modes", chooser);

		// Declaring sparks for drive code
		frontLeft = new Spark(0);
		rearLeft = new Spark(1);
		
		frontRight = new Spark(3);
		rearRight = new Spark(2);

		// Declaring controllers
		stick1 = new Joystick(0); // Port zero
		stick2 = new Joystick(1); // Port one

		// Declaring sparks for shooter
		shooter = new Spark(4);



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
	{/*
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
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
	}

	void TeleopInit()
	{
		//Inverting motors for the left side for forward drive
		rearLeft->SetInverted(true);
		frontLeft->SetInverted(true);



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
		//spinWheel = stick1 -> GetRawButton(11);
		//shooter -> Set(0.2); //testing shooter

		/*
		if (spinWheel)
		{
			shooter->Set(sparkPower);
		}
		else
		{
			shooter->Set(0);
		}
		*/

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
