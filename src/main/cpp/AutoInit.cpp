#include "Robot.h"

void Robot::AutonomousInit() {
    //automatically close arm during auto
    phenumatic_grabber.Set(frc::DoubleSolenoid::Value::kForward);
}