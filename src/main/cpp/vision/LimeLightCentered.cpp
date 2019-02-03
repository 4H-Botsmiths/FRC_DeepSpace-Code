#include "Robot.h"

bool Robot::limelightCentered() {
    return (
        limelight_area<limelight_area_acceptable &&
        limelight_area>-limelight_area_acceptable &&
        limelight_skew<limelight_skew_acceptable &&
        limelight_skew>-limelight_skew_acceptable &&
        limelight_offset_horz<limelight_offset_horz_acceptable &&
        limelight_offset_horz>-limelight_offset_horz_acceptable &&
        limelight_offset_vert<limelight_offset_vert_acceptable &&
        limelight_offset_vert>-limelight_offset_vert_acceptable
    );
}