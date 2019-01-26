#include "Robot.h"

void Robot::limelightMove(Robot::limelight_target_enum target) {
    if (limelightCheck(target)) {
        //
    }
    else {
        //if pipe isnt the same as the target, update to new pipe
        limelightUpdate(limelightConvert(target));
    }
}