#include "Robot.h"

void Robot::armConfirm() {
    if (!arm_started_front) {
        armUpdate();
        armToggle(); //flip arm
        while (arm_moving) armContinue(); //wait for arm to reach other side
    }
}