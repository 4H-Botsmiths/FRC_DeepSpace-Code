/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <array>
#include <frc/Spark.h>
#include <frc/Talon.h>
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/DigitalInput.h>
#include <frc/XboxController.h>
#include <frc/DoubleSolenoid.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/AnalogPotentiometer.h>
#include <networktables/NetworkTable.h>
#include <frc/smartdashboard/Smartdashboard.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
public:
	//core robot functions
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

	//helper functions
    //void ToggleSolenoid(frc::DoubleSolenoid& solenoid, bool& state); //invert a given solenoid
    void ToggleSolenoid(frc::DoubleSolenoid& solenoid); //invert a given solenoid
    double Deadzone(double v, double r); //prevents jitters while not moving
    double Deadzone(double v); //prevents jitters while not moving (applies default value)
    //double Cap(double v, double r); //prevents speed going to high
    void Move(double x, double y, double z); //deals with polarity
    void Move(double x, double y, double z, double t); //move for a certain amounut of time
    double Add(double i, double a);

    //different things the limelight returns that can be check whether we are centered
    enum limelight_value_enum { HORZ, AREA, SKEW };

	//limelight functions
    void limelightUpdate(); //updates the table data
    void limelightMove(); //move based on limelight info
    bool limelightCentered(limelight_value_enum value); //chgeck if certain param for limelight is centered

    //arm functions
    void armMove(double speed, double time);

    //file io
    void fileUpdate(); //updates the params of this class
    void fileCheckDouble(std::string val, double& org); //check if param is a double
    void fileCheckInt(std::string val, int& org); //check if param is an int

   private:
	//joysticks
    frc::XboxController controller_left { 0 }; //driver
    frc::XboxController controller_right { 1 }; //aux

    double controller_deadzone=0.15; //deadzone for triggers

    //shortens up typing
    frc::GenericHID::JoystickHand controller_lefthand=frc::GenericHID::JoystickHand::kLeftHand;
    frc::GenericHID::JoystickHand controller_righthand=frc::GenericHID::JoystickHand::kRightHand;

    //drive train motors + drive train
    frc::Talon drive_NW { 0 };
    frc::Talon drive_NE { 1 };
    frc::Talon drive_SE { 2 };
    frc::Talon drive_SW { 3 };
    frc::MecanumDrive drive_train { drive_NW, drive_SW, drive_NE, drive_SE };

    double drive_x_mult=1;
    double drive_y_mult=1;
    double drive_z_mult=1;

	//other motors
    frc::Spark arm { 4 };
    double arm_speed_putting=0.6; //arm needs more power when it has a gear
    double arm_speed_getting=0.55; //arm needs less power when it has no gear
    double arm_speed_endgame=0.3;
    double arm_timer=1.5; //how long in seconds to wait for arm to retract (endgame)
    bool arm_moving=false;
    bool arm_started_front=false; //stores what side arm started from

    //pneumatics
    frc::DoubleSolenoid pneumatic_grabber { 0, 1 }; //grabs hatches
    bool pneumatic_grabber_grabbing=true;

    frc::DoubleSolenoid pneumatic_ramp { 2, 3 }; //lowers arm and opens ramps at endgame
	bool pneumatic_ramp_active=false;

    frc::DoubleSolenoid pneumatic_endgame { 4, 5 }; //lowers arm and opens ramps at endgame
	bool pneumatic_endgame_active=false;

    int pneumatic_endgame_min=5; //min amount to press safety to deploy
    int pneumatic_endgame_safety=0; //makes sure that ramps dont deploy on accident

    //limelight objects
	std::shared_ptr<NetworkTable> limelight=nt::NetworkTableInstance::GetDefault().GetTable("limelight");

    //empty defines for current offsets
    double limelight_area=0;
    double limelight_skew=0;
    double limelight_offset_horz=0;

    //values must be within these ranges to be considered centered
    double limelight_area_acceptable=0.5;
    double limelight_skew_acceptable=2;
    double limelight_offset_horz_acceptable=0.5;

    //modifiers that change how much the bot is moved during auto
    double limelight_area_mult=0.1;
    double limelight_skew_mult=0.05;
    double limelight_offset_horz_mult=0.15;

    int limelight_stage=0; //how far along the limelight is in the auto tracking

    double limelight_stage_0_skew_min=0.05; //minimal amount to move in any given direction
    double limelight_stage_0_horz_min=0.1; //minimal amount to move in any given direction
    int limelight_stage_0_calibrating=0;
    int limelight_stage_0_centered=0; //timer for stage 0
    int limelight_stage_0_centered_wait=25; //wait x many frames
    int limelight_stage_0_calibrating_wait=50; //wait x many frames

    double limelight_stage_1_speed=0.2;

    double limelight_stage_3_forward_speed=0.25;
    double limelight_stage_3_forward_wait=2.0;
    double limelight_stage_3_backward_speed=0.2;
    double limelight_stage_3_backward_wait=1.0;

    //file system objects
    std::string filesys_path="/home/lvuser/params.txt"; //path of the parameter file
};