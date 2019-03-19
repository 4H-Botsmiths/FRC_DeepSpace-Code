#include "Robot.h"

#include <frc/DoubleSolenoid.h>

void Robot::ToggleSolenoid(frc::DoubleSolenoid& solenoid) {
    //moves solenoid based on bool state
    bool state=(solenoid.Get()==frc::DoubleSolenoid::Value::kReverse);
    state ? solenoid.Set(frc::DoubleSolenoid::Value::kForward) : solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    //state=!state; //invert state of solenoid
}