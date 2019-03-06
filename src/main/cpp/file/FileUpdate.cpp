#include "Robot.h"

#include <fstream>

void Robot::fileUpdate() {
    std::ifstream filesys(filesys_path);
    std::string current="";

    if (filesys.is_open()) {
        while (std::getline(filesys, current)) {
            std::string name=current.substr(0,current.find(":"));
            std::string val=current.substr(current.find(":")+1);

            //checks if param is set, if so try and convert it to new value
            if (name=="limelight_area_acceptable") { fileCheckDouble(val, limelight_area_acceptable); }
            else if (name=="limelight_skew_acceptable") { fileCheckDouble(val, limelight_skew_acceptable); }
            else if (name=="limelight_offset_horz_acceptable") { fileCheckDouble(val, limelight_offset_horz_acceptable); }
            else if (name=="limelight_area_mult") { fileCheckDouble(val, limelight_area_mult); }
            else if (name=="limelight_skew_mult") { fileCheckDouble(val, limelight_skew_mult); }
            else if (name=="limelight_offset_horz_mult") { fileCheckDouble(val, limelight_offset_horz_mult); }
            else if (name=="arm_speed_putting") { fileCheckDouble(val, arm_speed_putting); }
            else if (name=="arm_speed_getting") { fileCheckDouble(val, arm_speed_getting); }
            else if (name=="controller_deadzone") { fileCheckDouble(val, controller_deadzone); }
            else if (name=="arm_potentiometer_put") { fileCheckDouble(val, arm_potentiometer_put); }
            else if (name=="arm_potentiometer_get") { fileCheckDouble(val, arm_potentiometer_get); }
            else if (name=="drive_x_offset") { fileCheckDouble(val, drive_x_mult); }
            else if (name=="drive_y_offset") { fileCheckDouble(val, drive_y_mult); }
            else if (name=="drive_z_offset") { fileCheckDouble(val, drive_z_mult); }
            else if (name=="arm_speed_endgame") { fileCheckDouble(val, arm_speed_endgame); }
            else if (name=="arm_timer") { fileCheckDouble(val, arm_timer); }
            else if (name=="arm_potentiometer_mid") { fileCheckDouble(val, arm_potentiometer_mid); }
            else if (name=="limelight_stage_0_centered_wait") { fileCheckInt(val, limelight_stage_0_centered_wait); }
            else if (name=="limelight_stage_0_calibrating_wait") { fileCheckInt(val, limelight_stage_0_calibrating_wait); }
            else if (name=="limelight_stage_1_speed") { fileCheckDouble(val, limelight_stage_1_speed); }
            else if (name=="limelight_stage_3_forward_speed") { fileCheckDouble(val, limelight_stage_3_forward_speed); }
            else if (name=="limelight_stage_3_backward_speed") { fileCheckDouble(val, limelight_stage_3_backward_speed); }
            else if (name=="limelight_stage_3_forward_wait") { fileCheckDouble(val, limelight_stage_3_forward_wait); }
            else if (name=="limelight_stage_3_backward_wait") { fileCheckDouble(val, limelight_stage_3_backward_wait); }
        }
        filesys.close();
    }
}