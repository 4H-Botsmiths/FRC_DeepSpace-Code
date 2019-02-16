#include "Robot.h"

void Robot::armPutHatch() {
    if (!armPuttingHatch())
        arm.Set(arm_speed_putting);
    arm_moving=true;
    arm_started_front=false;
}