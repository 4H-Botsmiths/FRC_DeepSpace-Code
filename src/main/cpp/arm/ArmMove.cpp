#include "Robot.h"

void Robot::armMove(double speed, double time) {
    frc::Timer tmp;
    tmp.Start();
    while(!tmp.HasPeriodPassed(time)) {
        if (controller_left.GetXButton()) {
            break; //make sure that the user can press "x" to unstick blocking code
        }
        arm.Set(speed);
    }
    arm.Set(0);
}