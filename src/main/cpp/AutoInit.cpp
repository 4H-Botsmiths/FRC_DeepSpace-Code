#include "Robot.h"

#include <iostream>

void Robot::AutonomousInit() {
    ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing);
    TeleopInit();
}