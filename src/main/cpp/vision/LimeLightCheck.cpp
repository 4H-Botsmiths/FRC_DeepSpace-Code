#include "Robot.h"

bool Robot::limelightCheck(limelight_target_enum target) {
    //returns true if the current target is the same as the current pipe
    return limelight_pipe==limelightConvert(target);
}