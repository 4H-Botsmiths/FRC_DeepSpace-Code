#include "Robot.h"

void Robot::AutonomousInit() {
    //automatically close arm during auto
    pneumatic_grabber.Set(frc::DoubleSolenoid::Value::kForward);
}