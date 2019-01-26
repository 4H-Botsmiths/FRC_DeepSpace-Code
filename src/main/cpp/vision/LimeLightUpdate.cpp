#include "Robot.h"

void Robot::limelightUpdate(Robot::limelight_pattern_enum pattern) {
    limelight->PutNumber("pipeline", pattern); //makes sure we are checking for the correct tape layout
    limelight_pipe=pattern; //makes sure we are using the coorect pipeline 

    //update offsets
    limelight_offset_horz=limelight->GetNumber("tx", 0.0);
    limelight_offset_vert=limelight->GetNumber("ty", 0.0);
    limelight_area=limelight->GetNumber("ta", 0.0);
    limelight_skew=limelight->GetNumber("ts", 0.0);
}