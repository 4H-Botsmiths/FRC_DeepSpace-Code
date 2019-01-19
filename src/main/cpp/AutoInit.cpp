#include "Robot.h"

#include <iostream>

void Robot::AutonomousInit() {
	m_autoSelected = m_chooser.GetSelected();
	std::cout << "Auto selected: " << m_autoSelected << std::endl;

	if (m_autoSelected == kAutoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}