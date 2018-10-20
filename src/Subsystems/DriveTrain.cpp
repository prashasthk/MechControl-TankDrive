/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveTrain.h"
#include "Commands/TankDrive.h"
#include "ctre/Phoenix.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new TalonSRX(LEFTMOTOR)), right(new TalonSRX(RIGHTMOTOR)) {

}
void DriveTrain::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::tankDrive(double leftValue, double rightValue) {
left->Set(ControlMode::PercentOutput, leftValue);
right->Set(ControlMode::PercentOutput, rightValue);

}
void DriveTrain::leftDrive(double leftMotorVal) {
left->Set(ControlMode::PercentOutput, leftMotorVal);
}
void DriveTrain::rightDrive(double rightMotorVal) {
right->Set(ControlMode::PercentOutput, rightMotorVal);
}
