#include "Robot.h"

#include <frc/WPILib.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
	//allows for camera access
	camera_front=frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
	camera_back=frc::CameraServer::GetInstance()->StartAutomaticCapture(1);

	limelight->PutNumber("ledMode", 1); //turns off limelight lights while on feild
}