#include "Robot.h"
#include "toggle/toggle.cpp"

void Robot::TeleopPeriodic() {
    drive_train.DriveCartesian(
        controller_left.GetX(frc::GenericHID::JoystickHand::kLeftHand),
        controller_left.GetY(frc::GenericHID::JoystickHand::kLeftHand),
        controller_left.GetX(frc::GenericHID::JoystickHand::kRightHand)
    );

    arm.Set(controller_right.GetX(frc::GenericHID::JoystickHand::kRightHand));
}