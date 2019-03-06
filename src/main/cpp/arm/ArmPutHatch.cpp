#include "Robot.h"

void Robot::armPutHatch() {
    if (armGettingHatch()) {
        arm.Set(-arm_speed_getting);
        arm_moving=true;
        arm_started_front=false;
    }
}

void Robot::armForcePutHatch() {
    frc::Timer tmp;
    tmp.Start();
    while (!tmp.HasPeriodPassed(0.5)) {
        arm.Set(arm_speed_getting);
    }
    arm.Set(0);
}