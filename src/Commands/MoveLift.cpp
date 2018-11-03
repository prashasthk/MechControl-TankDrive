/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/MoveLift.h>
#include <iostream>

MoveLift::MoveLift() {
	Requires(Robot::lift);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveLift::Execute() {
double liftValue = Robot::m_oi->getLiftStick()->GetY();
Robot::lift->liftMove(liftValue);
//std::cout << Robot::lift->getHeight() << ", " << liftValue << std::endl;

}

// Make this return true when this Command no longer needs to run execute()
bool MoveLift::IsFinished() {
	return false;


}

// Called once after isFinished returns true
void MoveLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLift::Interrupted() {

}
