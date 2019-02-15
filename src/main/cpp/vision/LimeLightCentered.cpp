#include "Robot.h"

bool Robot::limelightCentered(Robot::limelight_value_enum value) {
    if (value==limelight_value_enum::HORZ)
        return (limelight_offset_horz<limelight_offset_horz_acceptable &&
            limelight_offset_horz>-limelight_offset_horz_acceptable);
    else if (value==limelight_value_enum::VERT)
        return (limelight_offset_vert<limelight_offset_vert_acceptable &&
            limelight_offset_vert>-limelight_offset_vert_acceptable);
    else if (value==limelight_value_enum::AREA)
        return (limelight_area<limelight_area_acceptable &&
            limelight_area>-limelight_area_acceptable);
    else if (value==limelight_value_enum::DIFF)
        return (limelight_tdiff<limelight_tdiff_acceptable &&
            limelight_tdiff>-limelight_tdiff_acceptable);
}