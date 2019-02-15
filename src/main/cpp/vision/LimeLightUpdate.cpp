#include "Robot.h"

void Robot::limelightUpdate() {
    //update values from limelight
    limelight_offset_horz=limelight->GetNumber("tx", 0.0); //middle of crosshair to center (X)
    limelight_offset_vert=limelight->GetNumber("ty", 0.0); //middle of crosshair to center (Y)
    limelight_valid=limelight->GetNumber("tv", 0.0); //0 if there is no target, 1 if there is
    limelight_area=limelight->GetNumber("ta", 0.0); //percent of target taking up screen
    limelight_skew=limelight->GetNumber("ts", 0.0); //angle of rotation
    limelight_tshort=limelight->GetNumber("tshort", 0.0); //length of shorter side
    limelight_tlong=limelight->GetNumber("tlong", 0.0); //length of longer side
    limelight_tdiff=limelight_tlong-limelight_tshort; //difference between long and short sides
}