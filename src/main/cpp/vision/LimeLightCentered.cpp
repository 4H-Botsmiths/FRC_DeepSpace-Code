#include "Robot.h"

bool Robot::limelightCentered(Robot::limelight_value_enum value) {
    if (value==limelight_value_enum::HORZ)
        return (limelight_offset_horz<limelight_offset_horz_acceptable &&
            limelight_offset_horz>-limelight_offset_horz_acceptable);
    else if (value==limelight_value_enum::AREA)
        return (limelight_area<limelight_area_acceptable &&
            limelight_area>-limelight_area_acceptable);
    else if (value==limelight_value_enum::SKEW)
        return (limelight_skew<limelight_skew_acceptable &&
            limelight_skew>-limelight_skew_acceptable);
    else return false;
}