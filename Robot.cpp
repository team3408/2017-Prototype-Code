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
	Joystick *left, *right;
	CanTalonSRX *rearLeft, *frontLeft, *rearRight, *frontRight; 

	void RobotInit()
	{
		chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*)&autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*)&autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);
		frontLeft = new CanTalonSRX(0);
		frontRight = new CanTalonSRX(1);
		rearLeft = new CanTalonSRX(2);
		rearRight = new CanTalonSRX(3);


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
		left = new Joystick(1);
		right = new Joystick(2);
		RoboDrive = new RobotDrive(frontLeft, rearLeft, frontRight, rearRight);
	}
	void TeleopPeriodic(){

		frontLeft -> Set(0.2);
		frontRight -> Set(0.2);
		rearLeft -> Set(0.2);
		rearRight ->Set(.2);
		RoboDrive->TankDrive(left,right);
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)

