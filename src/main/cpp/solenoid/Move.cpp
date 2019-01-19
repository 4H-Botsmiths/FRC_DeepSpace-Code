#include "Robot.h"

#include <frc/DoubleSolenoid.h>

void Robot::moveSolenoid(frc::DoubleSolenoid& solenoid, bool Move) {
    Move ? solenoid.Set(frc::DoubleSolenoid::Value::kForward) : solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}