/*
double limelight_area=0;
double limelight_skew=0;
double limelight_valid=0;
double limelight_offset_horz=0;
double limelight_offset_vert=0;
double limelight_tshort=0;
double limelight_tlong=0;
double limelight_tdiff=0;

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
#include <fstream>

void Robot::fileUpdate() {
    std::ifstream filesys(filesys_path);
    std::string current="";

    if (filesys.is_open()) {
        while (std::getline(filesys, current)) {
            std::string name=current.substr(0,current.find(":"));
            std::string val=current.substr(current.find(":")+1);

            //checks if param is set, if so try and convert it to new value
            if (name=="limelight_area_acceptable") fileCheckDouble(val, limelight_area_acceptable);
            else if (name=="limelight_skew_acceptable") fileCheckDouble(val, limelight_skew_acceptable);
            else if (name=="limelight_offset_horz_acceptable") fileCheckDouble(val, limelight_offset_horz_acceptable);
            else if (name=="limelight_offset_vert_acceptable") fileCheckDouble(val, limelight_offset_vert_acceptable);
            else if (name=="limelight_tshort_acceptable") fileCheckDouble(val, limelight_tshort_acceptable);
            else if (name=="limelight_tlong_acceptable") fileCheckDouble(val, limelight_tlong_acceptable);
            else if (name=="limelight_tdiff_acceptable") fileCheckDouble(val, limelight_tdiff_acceptable);
            else if (name=="limelight_area_mult") fileCheckDouble(val, limelight_area_mult);
            else if (name=="limelight_skew_mult") fileCheckDouble(val, limelight_skew_mult);
            else if (name=="limelight_offset_horz_mult") fileCheckDouble(val, limelight_offset_horz_mult);
            else if (name=="limelight_offset_vert_mult") fileCheckDouble(val, limelight_offset_vert_mult);
            else if (name=="limelight_tshort_mult") fileCheckDouble(val, limelight_tshort_mult);
            else if (name=="limelight_tlong_mult") fileCheckDouble(val, limelight_tlong_mult);
            else if (name=="limelight_tdiff_mult") fileCheckDouble(val, limelight_tdiff_mult);
            else if (name=="arm_speed_putting") fileCheckDouble(val, arm_speed_putting);
            else if (name=="arm_speed_getting") fileCheckDouble(val, arm_speed_getting);
            else if (name=="controller_deadzone") fileCheckDouble(val, controller_deadzone);
            else if (name=="arm_potentiometer_put") fileCheckDouble(val, arm_potentiometer_put);
            else if (name=="arm_potentiometer_get") fileCheckDouble(val, arm_potentiometer_get);
            else if (name=="drive_x_offset") fileCheckDouble(val, drive_x_mult);
            else if (name=="drive_y_offset") fileCheckDouble(val, drive_y_mult);
            else if (name=="drive_z_offset") fileCheckDouble(val, drive_z_mult);
            else if (name=="arm_speed_endgame") fileCheckDouble(val, arm_speed_endgame);
            else if (name=="arm_timer") fileCheckDouble(val, arm_timer);
            else if (name=="arm_potentiometer_mid") fileCheckDouble(val, arm_potentiometer_mid);
        }
        filesys.close();
    }
}