#include "Robot.h"

bool Robot::armPuttingHatch() {
    armUpdate();
    //returns true if arm is below the "put" value
    return (arm_potentiometer.Get()<arm_potentiometer_put);
}