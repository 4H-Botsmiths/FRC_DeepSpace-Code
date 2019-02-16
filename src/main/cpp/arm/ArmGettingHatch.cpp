#include "Robot.h"

bool Robot::armGettingHatch() {
    //returns true if arm is below the "get" value
    return (arm_potentiometer.Get()>arm_potentiometer_get);
}