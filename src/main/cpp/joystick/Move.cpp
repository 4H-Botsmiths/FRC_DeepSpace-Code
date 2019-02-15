#include "Robot.h"

void Robot::Move(double x, double y, double z) {
    drive_train.DriveCartesian(x, -y, z);
}
void Robot::Move(double x, double y, double z, double t) {
    frc::Timer timer;
    timer.Start();
    while (!timer.HasPeriodPassed(t)) {
        if (controller_right.GetTriggerAxis(controller_lefthand)>controller_deadzone)
            drive_train.DriveCartesian(x, -y, z);
        else break; //if the user lets go, stop moving
    }
    timer.Stop();
}