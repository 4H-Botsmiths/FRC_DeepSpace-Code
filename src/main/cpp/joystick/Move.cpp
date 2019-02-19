#include "Robot.h"

void Robot::Move(double x, double y, double z) {
    drive_train.DriveCartesian(
        -x*drive_x_mult,
        y*drive_y_mult,
        z*drive_z_mult
    );
}
void Robot::Move(double x, double y, double z, double t) {
    frc::Timer timer;
    timer.Start();
    while (!timer.HasPeriodPassed(t)) {
        if (controller_left.GetTriggerAxis(controller_lefthand)>controller_deadzone)
            Move(x, y, z);
        else break; //if the user lets go, stop moving
    }
    timer.Stop();
}