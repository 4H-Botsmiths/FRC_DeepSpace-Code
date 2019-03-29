#include "Robot.h"

void Robot::RobotPeriodic() {
    //clear cached button presses
    controller_right.GetAButtonPressed();
    controller_right.GetYButtonPressed();
}