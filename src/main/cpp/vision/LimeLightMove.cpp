#include "Robot.h"

#include <iostream>

void Robot::limelightMove(Robot::limelight_target_enum target) {
    limelightUpdate(limelightConvert(target)); //get most recent state
    if (limelightCheck(target)) { //check if the limelight is on the right pipe
        //drive till centered (x plane)
        drive_train.DriveCartesian(
            /* Cap(limelight_offset_horz, 0.5), */
            limelight_offset_horz*limelight_offset_horz_mult,
            0,
            0);
        std::cout << limelight_tlong << " " << limelight_tshort << std::endl;
    }
    else {
        //if pipe isnt the same as the target, update pipe again
        limelightUpdate(limelightConvert(target));
    }
}