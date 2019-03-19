#include "Robot.h"

void Robot::AutonomousInit() {
    phenumatic_grabber.Set(frc::DoubleSolenoid::Value::kForward);
    TeleopInit();
}