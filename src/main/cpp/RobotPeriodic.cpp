#include "Robot.h"

void Robot::RobotPeriodic() {
    controller_right.GetAButtonPressed();
    controller_right.GetYButtonPressed();
}