#include "Robot.h"

void Robot::armToggle() {
    arm_started_front?armGetHatch():armPutHatch();
    arm_started_front=!arm_started_front;
}