#include "Robot.h"

void Robot::armPutHatch() {
    if (!armPuttingHatch())
        arm.Set(-arm_speed_putting);
}