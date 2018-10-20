/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RightSpin.h"

RightSpin::RightSpin(double rightVal) {
	power = rightVal;
	Requires(Robot::drive);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RightSpin::Initialize() {
	SetTimeout(5);
}

// Called repeatedly when this Command is scheduled to run
void RightSpin::Execute() {
	Robot::drive->rightDrive(power);
}

// Make this return true when this Command no longer needs to run execute()
bool RightSpin::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void RightSpin::End() {
	Robot::drive->rightDrive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightSpin::Interrupted() {

}
