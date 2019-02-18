#include "Robot.h"

#include <iostream>

void Robot::limelightMove() {
    limelightUpdate();
    //center rotationaly and horizontaly
    if (limelight_stage==0) {
        if (!limelightCentered(limelight_value_enum::HORZ) || !limelightCentered(limelight_value_enum::SKEW)) {
            Move(
                limelight_offset_horz*limelight_offset_horz_mult,
                0,
                limelight_skew*limelight_skew_mult
            );
        }
        //dont enable stage 1 until stage 0 works
        //else limelight_stage=1;
    }
    //calculate distance to rocket
    if (limelight_stage==1) {
        //calulates the time required to reach wall
        limelight_time=limelight_area*limelight_area_mult;
        armConfirm(); //wait for arm to flip
        limelight_timer.Start(); //start timer
        Move(0, limelight_put_speed, 0); //start moving
        limelight_stage==2;
    }
    //keep driving until time has passed
    if (limelight_stage==2) {
        if (!limelight_timer.HasPeriodPassed(limelight_time))
            Move(0, limelight_put_speed, 0); //continue moving
        else limelight_stage==3;
    }
    //release hatch and reset vals
    if (limelight_stage==3) {
        ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing);
        limelight_stage=0; //reset stage
        limelight->PutNumber("ledMode", 1); //turn off limelight lights
    }
}