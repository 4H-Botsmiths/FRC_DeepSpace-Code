#include "Robot.h"

void Robot::limelightJitter() {
    //move over by N amount plus offset
    Move(
        Add(
            limelight_offset_horz*limelight_offset_horz_mult,
            limelight_jitter_horz_add
        )*!limelightCentered(limelight_value_enum::HORZ),
        0,
        Add(
            limelight_skew*limelight_skew_mult,
            limelight_jitter_skew_add
        )*!limelightCentered(limelight_value_enum::SKEW),
        limelight_jitter_move_time
    );
    //move back by offset amount
    //...
}