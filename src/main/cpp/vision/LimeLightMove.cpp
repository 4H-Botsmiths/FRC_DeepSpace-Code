#include "Robot.h"

#include <iostream>

void Robot::limelightMove(Robot::limelight_target_enum target) {
    if (limelightCheck(target)) { //check if the limelight is on the right pipe
        limelightUpdate(limelightConvert(target), false); //get most recent state

        //drive untill centered (rotational)
        if (!limelightCentered(limelight_value_enum::DIFF)) {
            //
        }

        //drive utill centered (left right)
        if (!limelightCentered(limelight_value_enum::HORZ)) {
            drive_train.DriveCartesian(
                limelight_offset_horz*limelight_offset_horz_mult,
                0,
                0
            );
        }
    }
    else {
        //if pipe isnt the same as the target, update pipe again
        limelightUpdate(limelightConvert(target), true);
    }
}