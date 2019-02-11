#include "Robot.h"

#include <iostream>

void Robot::limelightMove(Robot::limelight_target_enum target) {
    if (limelightCheck(target)) { //check if the limelight is on the right pipe
        limelightUpdate(limelightConvert(target), false); //get most recent state

        /*
        //drive untill centered (rotational)
        if (!limelightCentered(limelight_value_enum::DIFF)) {
            Move(0, 0, limelight_tdiff*limelight_tdiff_mult);
        }
        */

        //drive utill centered (left right)
        if (!limelightCentered(limelight_value_enum::HORZ)) {
            Move(limelight_offset_horz*limelight_offset_horz_mult, 0, 0);
        }
        //drive untill centered (forwards backwards)
        else if (!limelightCentered(limelight_value_enum::AREA)) {
            Move(0, limelight_area*limelight_area_mult, 0);
        }
        else { //after all centering is done
            arm.Set(arm_speed_putting); //send arm to other side
            if (armPuttingHatch()) { //wait for arm to be down
                //
            }
        }
    }
    else {
        //if pipe isnt the same as the target, update pipe again
        limelightUpdate(limelightConvert(target), true);
    }
}