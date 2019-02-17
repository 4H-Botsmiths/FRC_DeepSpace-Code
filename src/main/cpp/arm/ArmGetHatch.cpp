#include "Robot.h"

void Robot::armGetHatch() {
    if (armPuttingHatch()) {
        arm.Set(-arm_speed_getting);
        arm_moving=true;    
        arm_started_front=true; 
    }
}