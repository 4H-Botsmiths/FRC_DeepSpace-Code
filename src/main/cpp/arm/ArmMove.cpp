#include "Robot.h"

void Robot::armMove(double speed, double time) {
    frc::Timer tmp;
    tmp.Start();
    while(!tmp.HasPeriodPassed(time)) {
        if (controller_left.GetXButton()) {
            break;
        }
        arm.Set(speed);
    }
}