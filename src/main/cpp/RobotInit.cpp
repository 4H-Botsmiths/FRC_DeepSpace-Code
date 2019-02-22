#include "Robot.h"

#include <frc/WPILib.h>

void Robot::RobotInit() {
	//allows for camera access
	frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
	frc::CameraServer::GetInstance()->StartAutomaticCapture(1);

	limelight->PutNumber("ledMode", 1); //turns off limelight lights while on feild
}