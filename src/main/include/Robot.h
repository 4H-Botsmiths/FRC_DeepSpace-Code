/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/Spark.h>
#include <frc/Talon.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>
#include <frc/TimedRobot.h>
#include <frc/DoubleSolenoid.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override;
	void RobotPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

    void moveSolenoid(frc::DoubleSolenoid& solenoid, bool move);

private:
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;

	frc::Joystick left_stick{0};

	frc::Talon drive_NW{0};
	frc::Talon drive_NE{1};
	frc::Talon drive_SE{2};
	frc::Talon drive_SW{3};
	frc::MecanumDrive drive_train{drive_NW, drive_NE, drive_SE, drive_SW};

    frc::Spark spark_0 { 4 };
	frc::Spark spark_1 { 5 };
	frc::Spark spark_2 { 6 };

    frc::DoubleSolenoid solenoid_0 { 0, 1 };
	frc::DoubleSolenoid solenoid_1 { 2, 3 };
	frc::DoubleSolenoid solenoid_2 { 4, 5 };
};