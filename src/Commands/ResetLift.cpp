/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ResetLift.h"

ResetLift::ResetLift() {
	Requires(Robot::lift);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ResetLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ResetLift::Execute() {
	Robot::lift->liftMove(-0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool ResetLift::IsFinished() {
	if (Robot::lift->getLiftMotor()->GetSensorCollection().IsFwdLimitSwitchClosed()) {
		return true;
	}
	else
		return false;
}

// Called once after isFinished returns true
void ResetLift::End() {
	Robot::lift->resetEncoder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetLift::Interrupted() {

}
