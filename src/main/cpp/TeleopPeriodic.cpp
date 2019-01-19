#include "Robot.h"

void Robot::TeleopPeriodic() {
	drive_train.DriveCartesian(
		left_stick.GetX(),
		left_stick.GetY(),
		left_stick.GetZ());
}