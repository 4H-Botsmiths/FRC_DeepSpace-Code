/**
 * ----------------------------------------------------------------------------
 * Copyright (c) 2017-2018 FIRST. All Rights Reserved.
 * Open Source Software - may be modified and shared by FRC teams. The code
 * must be accompanied by the FIRST BSD license file in the root directory of
 * the project.
 * ----------------------------------------------------------------------------
 */

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
	m_autoSelected = m_chooser.GetSelected();
	std::cout << "Auto selected: " << m_autoSelected << std::endl;

	if (m_autoSelected == kAutoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::AutonomousPeriodic() {
	if (m_autoSelected == kAutoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
	drive_train.DriveCartesian(
		left_stick.GetX(),
		left_stick.GetY(),
		left_stick.GetZ());
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
	int main() { return frc::StartRobot<Robot>(); }
#endif