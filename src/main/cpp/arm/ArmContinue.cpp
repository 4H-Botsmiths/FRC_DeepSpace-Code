#include "Robot.h"

void Robot::armContinue() {
    if (arm_limit.Get()) {
        arm_moving=false; //stop arm from moving
        arm.Set(0);
    }
    else {
        arm_started_front?arm.Set(arm_speed_putting):arm.Set(-arm_speed_getting);
    }
}