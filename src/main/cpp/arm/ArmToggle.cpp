#include "Robot.h"

void Robot::armToggle() {
    arm_started_front?armGetHatch():armPutHatch();
    arm_started_front=!arm_started_front;
}

void Robot::armForceToggle() {
    arm_started_front?armForceGetHatch():armForcePutHatch();
    arm_started_front=!arm_started_front;
}