#include "Robot.h"

#include <iostream>

void Robot::limelightMove() {
    limelightUpdate();
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