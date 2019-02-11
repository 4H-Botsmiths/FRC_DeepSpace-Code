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
        Move(
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(controller_left.GetY(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kRightHand))
        );
        if (controller_left.GetAButtonPressed()) {
            camera_server.SetSource(camera_front);
        }
        else if (controller_left.GetBButtonPressed()) {
            camera_server.SetSource(camera_back);
        }
        if (controller_right.GetXButton()) {
            //armPutHatch();
            arm.Set(0.4);
        }
        else if (controller_right.GetBButton()) {
            //armGetHatch();
            arm.Set(-0.4);
        }
        else {
            arm.Set(0);
        }
        if (controller_right.GetAButtonPressed())
            ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing); //grabs

        if (controller_right.GetYButtonPressed()) phenumatic_endgame_safety++;

        if (phenumatic_endgame_safety>=phenumatic_endgame_min) {
            phenumatic_endgame.Set(frc::DoubleSolenoid::kForward);
            phenumatic_ramp.Set(frc::DoubleSolenoid::kForward);
            frc::Timer tmp;
            tmp.Start();
            while (!tmp.HasPeriodPassed(1.5)) {
                arm.Set(-arm_speed_putting);
            }
            tmp.Stop();
            arm.Set(0);
            phenumatic_ramp.Set(frc::DoubleSolenoid::kReverse);
            phenumatic_endgame_safety=0;
        }
        if (controller_right.GetBackButtonPressed()) {
            phenumatic_endgame.Set(frc::DoubleSolenoid::kReverse);
        }
    }
    else {
        //auto targetting
        //for now, only one target will be assumed (hatch)
        limelightMove(limelight_target_enum::ROCKET_HATCH_UPPER);
    }
}