#include "Robot.h"

#include <frc/DoubleSolenoid.h>

void Robot::ToggleSolenoid(frc::DoubleSolenoid& solenoid, bool &state) {
    //moves solenoid based on bool state
    state ? solenoid.Set(frc::DoubleSolenoid::Value::kForward) : solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    state=!state; //invert state of solenoid
}