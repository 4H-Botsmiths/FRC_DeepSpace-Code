#include "Robot.h"

#include <frc/DoubleSolenoid.h>

void Robot::toggleSolenoid(frc::DoubleSolenoid& solenoid) {
    //moves solenoid based on bool state
    phenumatic_grabber_grabbing ? solenoid.Set(frc::DoubleSolenoid::Value::kForward) : solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
    phenumatic_grabber_grabbing=(!phenumatic_grabber_grabbing); //invert state of solenoid
}