#include "Robot.h"

void Robot::armUpdate() { //updates potentiometer value
    arm_potentiometer_current=arm_potentiometer.Get();
}