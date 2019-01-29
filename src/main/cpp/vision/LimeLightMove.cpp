#include "Robot.h"

void Robot::limelightMove(Robot::limelight_target_enum target) {
    if (limelightCheck(target)) { //check if the limelight is on the right pipe
        //do move stuff
    }
    else {
        //if pipe isnt the same as the target, update to new pipe
        limelightUpdate(limelightConvert(target));
    }
}