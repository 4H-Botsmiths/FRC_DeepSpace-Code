#include "Robot.h"

void Robot::armGetHatch() {
    if (!armGettingHatch())
        arm.Set(arm_speed);
}