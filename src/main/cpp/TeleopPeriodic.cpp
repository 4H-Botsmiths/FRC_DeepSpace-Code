#include "Robot.h"

#include <iostream>

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
        //uncomment this when/if a potentiometer is added
        //if (controller_right.GetXButtonPressed()) armPutHatch();
        //else if (controller_right.GetBButtonReleased()) armGetHatch();
        
        if (controller_right.GetXButton()) arm.Set(arm_speed_getting);
        else if (controller_right.GetBButton()) arm.Set(-arm_speed_putting);
        else arm.Set(0);

        if (controller_right.GetAButtonPressed())
            ToggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing); //grabs

        if (controller_right.GetYButtonPressed()) phenumatic_endgame_safety++;

        if (phenumatic_endgame_safety>=phenumatic_endgame_min) { //if the saftey has been tripped run endgame sequence
            phenumatic_endgame.Set(frc::DoubleSolenoid::kForward); //retracts lower arm
            phenumatic_ramp.Set(frc::DoubleSolenoid::kForward); //pushes out ramp
            frc::Timer tmp;
            tmp.Start();
            while (!tmp.HasPeriodPassed(arm_timer)) { //wait 1.5 seconds
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
        limelightMove(); //auto targeting
    }
}