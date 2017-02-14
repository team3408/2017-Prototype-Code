#include "WPILib.h"
#include <Timer.h>
#include "SmartDashboard/SmartDashboard.h"

class Robot: public IterativeRobot
{


private:
	/*
	LiveWindow *lw = LiveWindow::GetInstance();

	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;

	SendableChooser *Chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
	*/

	// Declaring variables and calling instances of classes
	RobotDrive *RoboDrive;
	Joystick *stick1, *stick2;
	Spark *rearLeft, *frontLeft, *rearRight, *frontRight, *shooter, *climber;
	Encoder *robotDistance;
	double leftWheels;
	double rightWheels;
	bool spinWheel;
	bool climberForwardSpin;
	bool climberReverseSpin;
	double Kp= 0.1;
	bool done = false;

	double revolutions;
	double pulse;

	AnalogGyro *gyro;

	//double sparkPower = 0.5;

	Timer *autotimer;
	//Timer *totalTime;
	double stopTime;

	// SmartDashboard
	//SmartDashboard *runTimer;
	double angleMeasurement;

	RobotDrive *myDrive;

	//CameraServer *camera;

	void RobotInit()
	{
		/*
		chooser = new <SendableChooser>SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);
		*/

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

		gyro = new AnalogGyro(0);

		//chooser = new SendableChooser();

		// Inverting motors


		// Encoder code
		//lw->AddActuator("spark4", "Shooter", shooter);

		myDrive = new RobotDrive(frontLeft, rearLeft, rearRight, frontRight);
/*
 	 	camera = new CameraServer();
 	 	camera->AddAxisCamera("Axis Camera");
		camera->StartAutomaticCapture("Axis Camera", 0);
*/
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

		gyro->Reset();
		gyro->Calibrate();
		autotimer->Reset();
		done = false;

		rearLeft->SetInverted(true);
		frontLeft->SetInverted(true);
		angleMeasurement = gyro->GetAngle();
		angleMeasurement = angleMeasurement/360;
		SmartDashboard::PutNumber("Gyro Angle", angleMeasurement);
		Wait(1);
		autotimer->Start();

		//frontLeft->SetInverted(true);
		//rearLeft->SetInverted(true);


		/*
		autoSelected = *((std::string*)chooser->GetSelected());
		std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;
		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
		*/
	}

	void AutonomousPeriodic()
	{
		angleMeasurement = gyro->GetAngle();
		SmartDashboard::PutNumber("Gyro Angle", angleMeasurement);

/*
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
*/
	if(autotimer->HasPeriodPassed(3.5))
	{
		myDrive->ArcadeDrive(0.0,0.0);
		done = true;
	}
	else if(done)
	{
		myDrive->ArcadeDrive(0.0,0.0);
	}
	else
	{
		myDrive->ArcadeDrive(angleMeasurement, 0.65);
	}

	//Right-Side Code
	myDrive -> ArcadeDrive(0.0,0.5);
	revolutions = robotDistance -> GetDistance();
	if (revolutions >= 4.2)
	{
		myDrive->ArcadeDrive(-30,0.0);
		robotDistance->Reset();
		Wait(0.5);
		myDrive->ArcadeDrive(-30,0.5);
		revolutions = robotDistance -> GetDistance();
		if (revolutions > 4.03)
		{
			myDrive->ArcadeDrive(-30,0.0);
		}
	}

	//Left-Side Code
		myDrive -> ArcadeDrive(0.0,0.5);
		revolutions = robotDistance -> GetDistance();
		if (revolutions >= 4.2)
		{
			myDrive->ArcadeDrive(30,0.0);
			robotDistance->Reset();
			Wait(500);
			myDrive->ArcadeDrive(30,0.5);
			revolutions = robotDistance -> GetDistance();
			if (revolutions > 4.03)
			{
				myDrive->ArcadeDrive(30,0.0);
			}


		}

	}
	void TeleopInit()
	{
		gyro->Reset();
		gyro->Calibrate();
		// Testing SmartDashboard
		//totalTime -> Start();
		//SmartDashboard::PutNumber("Run Time", totalTime->runTimer());
		rearRight->SetInverted(true);
		frontRight->SetInverted(true);
		//done = false;


	}
	void TeleopPeriodic()
	{
		angleMeasurement = gyro->GetAngle();
		SmartDashboard::PutNumber("Gyro Angle", angleMeasurement);
		//DRIVE CODE
		leftWheels = stick1 -> GetRawAxis(1); //leftwheels doesnt work
		rightWheels = stick1 -> GetRawAxis(5);
		frontLeft -> Set(rightWheels);
		frontRight -> Set(leftWheels);
		rearLeft -> Set(rightWheels);
		rearRight -> Set(leftWheels);

		//SHOOTER CODE
		spinWheel = stick1 -> GetRawButton(1);
		//shooter -> Set(0.8); //testing shooter

		climberForwardSpin = stick1 -> GetRawButton(2);

		climberReverseSpin = stick1 -> GetRawButton(3);

		if (spinWheel)
		{
			shooter->Set(-0.7);
		}
		else
		{
			shooter->Set(0);
		}

		if (climberForwardSpin)
		{
			climber->Set(1);
		}
		else
		{
			climber->Set(0);
		}

		if (climberReverseSpin)
		{
			climber->Set(-1);
		}
		else
		{
			climber->Set(0);
		}


/*
		leftWheels = stick1 -> GetRawAxis(1);
		rightWheels = stick1 -> GetRawAxis(5);


		myDrive->ArcadeDrive(-leftWheels,rightWheels);*/
	}

	void TestPeriodic()
	{
		//lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
