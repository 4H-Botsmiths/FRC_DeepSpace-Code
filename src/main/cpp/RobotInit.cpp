#include "Robot.h"

#include <frc/WPILib.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
	//allows for camera access
	frc::CameraServer::GetInstance()->StartAutomaticCapture();

	m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
	m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}