/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Commands/TankDrive.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "../RobotMap.h"

class DriveTrain : public frc::Subsystem {
private:
	TalonSRX*left;
	TalonSRX*right;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	DriveTrain();
	~DriveTrain();
	void InitDefaultCommand() override;
	void tankDrive(double leftValue, double rightValue);
};

