/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoMoveLift.h"

AutoMoveLift::AutoMoveLift(double setpoint) :
liftPID(new WVPIDController(liftKp, liftKi, liftKd, target, false)){
	Requires(Robot::lift);
	target = setpoint;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoMoveLift::Initialize() {
Robot::lift->resetEncoder();
liftPID->SetSetPoint(target);
}

// Called repeatedly when this Command is scheduled to run
void AutoMoveLift::Execute() {
power = liftPID->Tick(Robot::lift->getHeight());
Robot::lift->liftMove(0.15 + power);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoMoveLift::IsFinished() {
	if (fabs(liftPID->GetError()) < 0.05) {
		return true;
	}
	else if (Robot::lift->getLiftMotor()->GetSensorCollection().IsRevLimitSwitchClosed()) {
		return true;
	}
	else
		return false;

}

// Called once after isFinished returns true
void AutoMoveLift::End() {
	Robot::lift->liftMove(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMoveLift::Interrupted() {

}
