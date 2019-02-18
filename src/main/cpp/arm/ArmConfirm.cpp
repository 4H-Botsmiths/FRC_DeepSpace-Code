#include "Robot.h"

void Robot::armConfirm() {
    armUpdate();
    armToggle(); //flip arm
    while (arm_moving) armContinue(); //wait for arm to reach other side
}