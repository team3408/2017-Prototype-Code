#include "WPILib.h"
#include <"CanTalon.h">

class Robot: public IterativeRobot
{


private:
	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
	RobotDrive *RoboDrive;
	Joystick *stick1, *stick2;
	CanTalonSRX *rearLeft, *frontLeft, *rearRight, *frontRight;
	double MotorSpeed = .2;
	float leftWheels;
	float rightWheels;

	void RobotInit()
	{
		chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);
		frontLeft = new CanTalonSRX();
		frontRight = new CanTalonSRX();
		rearLeft = new CanTalonSRX();
		rearRight = new CanTalonSRX();


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
		autoSelected = *((std::string*)chooser->GetSelected());
		//std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;

		if(autoSelected == autoNameCustom){
			//Custom Auto goes here
		} else {
			//Default Auto goes here
		}
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
		stick1 = new Joystick(1);
		stick2 = new Joystick(2);
		
		
	}
	void TeleopPeriodic()
	{
		stick1 -> GetRawAxis(2);
		stick1 -> GetRawAxis(4);
		leftWheels = frontLeft -> Set(MotorSpeed);
		rightWheels = frontRight -> Set(MotorSpeed);
		leftWheels = rearLeft -> Set(MotorSpeed);
		rightWheels = rearRight -> Set(MotorSpeed);
		
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
