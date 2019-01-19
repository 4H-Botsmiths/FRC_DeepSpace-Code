#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
	m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
	m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}