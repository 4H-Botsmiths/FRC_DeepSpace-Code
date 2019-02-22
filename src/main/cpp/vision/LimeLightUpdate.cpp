#include "Robot.h"

void Robot::limelightUpdate() {
    //update values from limelight
    limelight_offset_horz=limelight->GetNumber("tx", 0.0); //middle of crosshair to center (X)
    limelight_area=limelight->GetNumber("ta", 0.0); //percent of target taking up screen
    limelight_skew=limelight->GetNumber("ts", 0.0); //angle of rotation

    //make sure the skew has a usable polarity
    if (limelight_skew<-45) limelight_skew+=90; //make limelight skew usable
    limelight_skew*=-1;
}