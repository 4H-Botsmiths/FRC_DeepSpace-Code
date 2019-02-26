#include "Robot.h"

#include <iostream>

/* Controler layout:
CONTROLLER_RIGHT:
    A_BUTTON: toggle hatch grabber
    B_BUTTON: toggle arm side
    Y_BUTTON: (x5) deploy ramps
CONTROLLER_LEFT:
    LEFT_TRIGGER: auto align
    X_AXIS_RIGHT: rotate
    X_AXIS_LEFT: strafe
    Y_AXIS_LEFT: forward/backward
*/

void Robot::TeleopPeriodic() {
    //if left trigger is being held, switch to auto tracking, human input will be ignored
    //releasing left trigger will restore control and turn off auto tracking
    if (!controller_left.GetTriggerAxis(controller_lefthand)>controller_deadzone) {
        limelight_stage_0_calibrating=0;
        limelight_stage_0_centered=0;
        limelight->PutNumber("ledMode", 1); //turn off limelight lights
        limelight_stage=0;
        
        Move(
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(controller_left.GetY(frc::GenericHID::JoystickHand::kLeftHand)),
            Deadzone(controller_left.GetX(frc::GenericHID::JoystickHand::kRightHand))
        );
        //uncomment this when/if a potentiometer is added
        armUpdate();
        if (!arm_moving) {
            if (controller_right.GetBButtonPressed()) armToggle();
        }
        else armContinue();

        if (controller_right.GetAButtonPressed())
            ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing); //grabs

        if (controller_right.GetYButtonPressed()) phenumatic_endgame_safety++;

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

        if (controller_right.GetBackButtonPressed()) //raises lower arm (for debugging)
            phenumatic_endgame.Set(frc::DoubleSolenoid::kReverse);
    }
    else {
        limelight->PutNumber("ledMode", 3); //turn on limelight lights
        limelightMove(); //auto targeting
    }
}