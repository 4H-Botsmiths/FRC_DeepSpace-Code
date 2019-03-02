#include "Robot.h"

#include <iostream>

void Robot::limelightMove(bool force) {
    limelightUpdate();
    limelight->PutNumber("ledMode", 3); //turn on limelight lights
    //center rotationaly and horizontaly
    if (limelight_stage==0) {
        if ((!limelightCentered(limelight_value_enum::HORZ) ||
            !limelightCentered(limelight_value_enum::SKEW)) ||
            limelight_stage_0_calibrating < limelight_stage_0_calibrating_wait
            ) {
            Move(
                Add(limelight_offset_horz*limelight_offset_horz_mult, limelight_stage_0_horz_min),
                0,
                limelight_skew*limelight_skew_mult
            );
            limelight_stage_0_centered=0;
            limelight_stage_0_calibrating++;
        }
        else if (limelight_stage_0_calibrating>=limelight_stage_0_calibrating_wait) {
            limelight_stage=1;
        }
        else {
            limelight_stage_0_calibrating=0;
            limelight_stage_0_centered++;
            if (limelight_stage_0_centered>=limelight_stage_0_centered_wait)
                limelight_stage=1;
        }
    }
    //keep driving until time has passed
    else if (limelight_stage==1) {
        limelight_stage_0_calibrating=0;
        limelight_stage_0_centered=0;
        if (limelight_area<2.5)
            Move(0, -limelight_stage_1_speed, 0); //continue moving
        else limelight_stage=2;
    }
    //toggle grabber and reset vals
    else if (limelight_stage==2) {
        if (force) armForcePutHatch();
        else armConfirm(false);
        
        Move(0, -limelight_stage_3_forward_speed, 0, limelight_stage_3_forward_wait);
        ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing);
        Move(0, limelight_stage_3_backward_speed, 0, limelight_stage_3_backward_wait);
        limelight_stage=-1; //reset stage
        limelight->PutNumber("ledMode", 1); //turn off limelight lights
    }
}