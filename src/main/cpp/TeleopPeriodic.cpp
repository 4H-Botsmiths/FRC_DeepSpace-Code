#include "Robot.h"
#include "toggle/toggle.cpp"

void Robot::TeleopPeriodic() {
    drive_train.DriveCartesian(
        left_stick.GetX(),
        left_stick.GetY(),
        left_stick.GetZ());

    moveSolenoid(solenoid_0, left_stick.GetRawButtonPressed(1));
	moveSolenoid(solenoid_1, left_stick.GetRawButtonPressed(2));
	moveSolenoid(solenoid_2, left_stick.GetRawButtonPressed(3));
}