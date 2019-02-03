#include "Robot.h"

/* Controler layout:
CONTROLLER_RIGHT:
    LEFT_TRIGGER: auto align
    A_BUTTON: toggle hatch grabber
    B_BUTTON: flip for feeder
    X_BUTTON: flip for auto
    Y_BUTTON: (x5) deploy ramps
CONTROLLER_LEFT:
    X_AXIS_RIGHT: rotate
    X_AXIS_LEFT: strafe
    Y_AXIS_LEFT: forward/backward
*/

void Robot::TeleopPeriodic() {
    //if left trigger is being held, switch to auto tracking, human input will be ignored
    //releasing left trigger will restore control and turn off auto tracking
    if (!controller_right.GetTriggerAxis(controller_lefthand)>controller_deadzone) {
        drive_train.DriveCartesian(
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(-controller_left.GetY(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kRightHand))
        );
        if (controller_right.GetXButton())
            arm.Set(arm_speed);

        else if (controller_right.GetBButton())
            arm.Set(-arm_speed);

        if (controller_right.GetAButtonPressed())
            ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing); //grabs

        if (controller_right.GetYButtonPressed()) phenumatic_endgame_safety++;

        if (phenumatic_endgame_safety>=phenumatic_endgame_min) {
            //deploy ramps
        }
    }
    else {
        //auto targetting
        //for now, only one target will be assumed (hatch)
        limelightMove(limelight_target_enum::ROCKET_HATCH_UPPER);
    }
}