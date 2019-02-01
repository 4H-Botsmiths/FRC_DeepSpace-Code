#include "Robot.h"

void Robot::TeleopPeriodic() {
    if (!controller_right.GetAButton()) {
        drive_train.DriveCartesian(
            controller_left.GetX(frc::GenericHID::JoystickHand::kLeftHand),
            controller_left.GetY(frc::GenericHID::JoystickHand::kLeftHand),
            controller_left.GetX(frc::GenericHID::JoystickHand::kRightHand)
        );

        arm.Set(controller_right.GetX(frc::GenericHID::JoystickHand::kRightHand));

        if (controller_right.GetBButtonPressed()) {
            toggleSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing); //grabs
        }
        if (controller_right.GetYButtonPressed()) phenumatic_deployer_safety++;

        if (phenumatic_deployer_safety>=phenumatic_deployer_min) {
            //deploy ramps
        }
    }
    else {
        //auto targetting
    }
}