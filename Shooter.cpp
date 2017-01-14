#include "WPILib.h"
#include <math.h>

class Robot: public IterativeRobot{

private:

  void RobotInit(){
    JoystickButton * spinWheel
    CanTalonSRX * Talon5
    CanTalonSRX * Talon6
    int spinWheel = JoystickButton(8);
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
