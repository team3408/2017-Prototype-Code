#include "WPILib.h"
#include <math.h>
//things to do
//Make shooter move
//have shooter have multiple power values ie. use 10 buttons
//Output the motor value
//Encoder Speed output
//Test with talon after sparks move
/*
bool shoot10;
bool shoot20;
bool shoot30;
bool shoot40;
bool shoot50;
bool shoot60;
bool shoot70;
bool shoot80;
bool shoot90;
*/

Joystick*spinWheel;
Spark*Spark3;
double sparkPower = 0.5;

class Robot: public IterativeRobot{

private:

  void RobotInit(){
    spinWheel = Stick2 -> GetRawButton(7);
  }

  void AutonomousInit(){

  }

  void TeleopInit(){
      Spark3 = new Spark(3);
  }

  void TestPeriodic(){
	  if (spinWheel) {
		  Spark3->Set(sparkPower);
	  }
	  else {
		  Spark3->Set(0);
	  }
  }
};

START_ROBOT_CLASS(Robot)
