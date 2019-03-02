#include "Robot.h"

void Robot::armGetHatch() {
    if (armPuttingHatch()) {
        arm.Set(arm_speed_putting);
        arm_moving=true;
        arm_started_front=true;
    }
}

void Robot::armForceGetHatch() {
    frc::Timer tmp;
    tmp.Start();
    while (!tmp.HasPeriodPassed(0.5)) arm.Set(arm_speed_putting);
}