#include "Robot.h"
#include "toggle/toggle.cpp"

void Robot::TeleopPeriodic() {
    drive_train.DriveCartesian(
        controller_left.GetX(frc::GenericHID::JoystickHand::kLeftHand),
        controller_left.GetY(frc::GenericHID::JoystickHand::kLeftHand),
        controller_left.GetX(frc::GenericHID::JoystickHand::kRightHand)
    );

    arm.Set(controller_right.GetX(frc::GenericHID::JoystickHand::kRightHand));
    if (controller_right.GetAButtonPressed()) {
        phenumatic_grabber_grabbing=(!phenumatic_grabber_grabbing); //inverts state
        //moveSolenoid(phenumatic_grabber, phenumatic_grabber_grabbing); //grabs
    }
    if (controller_right.GetXButtonPressed()) phenumatic_deployer_safety++;

    if (phenumatic_deployer_safety>=phenumatic_deployer_min) {
        //deplor ramps
    }
}