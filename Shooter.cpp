#include "WPILib.h"
#include <math.h>
//things to do
//Make shooter move
//have shooter have multiple power values ie. use 10 buttons
//Output the motor value
//Encoder Speed output
//Test with talon after sparks move
public bool shoot10;
public bool shoot20;
public bool shoot30;
public bool shoot40;
public bool shoot50;
public bool shoot60;
public bool shoot70;
public bool shoot80;
public bool shoot90;

class Robot: public IterativeRobot{

private:

  void RobotInit(){
    JoystickButton * spinWheel
    CanTalonSRX * Talon5
    CanTalonSRX * Talon6
    spinWheel = new JoystickButton(8);
  }

  void AutonomousInit(){

  }

  void TeleopInit(){
    void Shoot(){
      Talon5 = new CanTalonSRX(5);
      Talon6 = new CanTalonSRX(6);
      float talonPower = 0.5;
      Talon5->Set(talonPower);
      Talon6->Set(talonPower);
    }

  }

  void TestPeriodic(){
    spinWheel->WhileHeld(Shoot());
  }
};

START_ROBOT_CLASS(Robot)
