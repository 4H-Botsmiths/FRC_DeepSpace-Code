#include "Robot.h"

void Robot::armConfirm() {
    if (!arm_started_front) {
        armUpdate();
        armToggle(); //flip arm
        while (arm_moving) {
            armContinue(); //wait for arm to reach other side
        }
    }
}

void Robot::armConfirm(bool gethatch) { //set arm to certain spot only if its not there already
    if (armGettingHatch() && !gethatch || armPuttingHatch() && gethatch) {
        armConfirm();
    }
}