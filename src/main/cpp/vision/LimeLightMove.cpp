#include "Robot.h"

#include <iostream>

void Robot::limelightMove(Robot::limelight_target_enum target) {
    limelightUpdate(limelightConvert(target)); //get most recent state
    if (limelightCheck(target)) { //check if the limelight is on the right pipe
        //drive till centered (x plane)
        drive_train.DriveCartesian(
            (limelight_offset_horz<0?-0.25:0.25),
            0,
            0);
    }
    else {
        //if pipe isnt the same as the target, update pipe again
        limelightUpdate(limelightConvert(target));
    }
}