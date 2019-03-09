#include "Robot.h"

#include <iostream>

/* Controler layout:
CONTROLLER_RIGHT:
    A_BUTTON: toggle hatch grabber
    Y_BUTTON: (x5) deploy ramps
    LEFT_TRIGGER: move arm (to put)
    RIGHT_TRIGGER: move arm (to get)
CONTROLLER_LEFT:
    LEFT_TRIGGER: auto align
    X_AXIS_RIGHT: rotate
    X_AXIS_LEFT: strafe
    Y_AXIS_LEFT: forward/backward
*/

void Robot::TeleopPeriodic() {
    //if left trigger is being held, switch to auto tracking, human input will be ignored
    //releasing left trigger will restore control and turn off auto tracking
    if (controller_left.GetTriggerAxis(controller_lefthand)>controller_deadzone) {
        limelightMove(); //auto targeting
    }
    else {
        limelight_stage_0_calibrating=0;
        limelight_stage_0_centered=0;
        limelight->PutNumber("ledMode", 1); //turn off limelight lights
        limelight_stage=0;
        
        Move(
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(controller_left.GetY(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kRightHand))
        );

        if (controller_right.GetTriggerAxis(controller_lefthand)>0.1) {
            arm.Set(Deadzone(controller_right.GetTriggerAxis(controller_lefthand), 0.1)*arm_speed_getting);
        }
        else if (controller_right.GetTriggerAxis(controller_righthand)>0.1) {
            arm.Set(Deadzone(controller_right.GetTriggerAxis(controller_righthand), 0.1)*-arm_speed_putting);
        }
        else {
            arm.Set(0);
        }

        if (controller_right.GetAButtonPressed()) {
            ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing); //grabs
        }

        if (controller_right.GetYButtonPressed()) {
            phenumatic_endgame_safety++;
        }

        if (phenumatic_endgame_safety>=phenumatic_endgame_min) { //if the saftey has been tripped run endgame sequence
            phenumatic_endgame.Set(frc::DoubleSolenoid::kForward); //retracts lower arm
            phenumatic_ramp.Set(frc::DoubleSolenoid::kForward); //pushes out ramp
            frc::Timer tmp;
            tmp.Start();
            while (!tmp.HasPeriodPassed(arm_timer)) { //move arm down
                arm.Set(-arm_speed_endgame); //makes sure arm goes inside frame
            }
            tmp.Stop(); //stop timer
            arm.Set(0); //stop arm from moving
            phenumatic_ramp.Set(frc::DoubleSolenoid::kReverse); //retract ramp piston
            phenumatic_endgame_safety=0; //make it so endgame can be ran again if it doesnt work
        }

        if (controller_right.GetBackButtonPressed()) { //raises lower arm (resets arm)
            armMove(0.4, 0.6);
            phenumatic_endgame.Set(frc::DoubleSolenoid::kReverse);
        }
    }
}