/*
double limelight_area=0;
    double limelight_skew=0;
    double limelight_valid=0;
    double limelight_offset_horz=0;
    double limelight_offset_vert=0;
    double limelight_tshort=0;
    double limelight_tlong=0;
    double limelight_tdiff=0;
*/
/*

    //values must be within these ranges to be considered centered
    double limelight_area_acceptable=0.5; 
    double limelight_skew_acceptable=0.5;
    double limelight_offset_horz_acceptable=0.5;
    double limelight_offset_vert_acceptable=0.5;
    double limelight_tshort_acceptable=0;
    double limelight_tlong_acceptable=0;
    double limelight_tdiff_acceptable=0; //difference between long and short

    //modifiers that change how much the bot is moved during auto
    double limelight_area_mult=0.1;
    double limelight_skew_mult=0.1;
    double limelight_offset_horz_mult=0.1;
    double limelight_offset_vert_mult=0.1;
    double limelight_tshort_mult=0;
    double limelight_tlong_mult=0;
    double limelight_tdiff_mult=0;

    //camera objects
    cs::UsbCamera camera_front;
    cs::UsbCamera camera_back;
    cs::VideoSink camera_server;
    bool camera_front_active=true;
*/

#include "Robot.h"

#include <iostream>

/*
void Robot::fileUpdate() {
    std::ifstream filesys(filesys_path);
    std::string current="";

    if (filesys.is_open()) {
        while (std::getline(filesys, current)) {
            std::String[] params=current.split(":");

            //checks if param is set, if so try and convert it to new value
            if (parmas[0] == "limelight_area") fileCheckDouble(params[1], limelight_area);
        }
        filesys.close();
    }
}
*/