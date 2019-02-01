#include "Robot.h"

Robot::limelight_pattern_enum Robot::limelightConvert(Robot::limelight_target_enum target) {
    //targets using ground line pattern
    if (target==0 || target==1 || target==4 || target==7 || target==9 || target==11 || target==13)
        return limelight_pattern_enum::GROUND;
    
    //targets using hatch panel pattern
    else if (target==5 || target==6 || target==10 || target==12 || target==14)
        return limelight_pattern_enum::HATCHES;

    //targets using the left feeder station upper pattern
    else if (target==2 || target==3)
        return limelight_pattern_enum::FEEDER_LEFT;

    //targets using the rocket's ball low goal pattern
    else
        return limelight_pattern_enum::BALL;
}