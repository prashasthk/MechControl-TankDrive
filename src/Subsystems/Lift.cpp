/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/MoveLift.h>
#include "Lift.h"
#include "../RobotMap.h"


Lift::Lift() : Subsystem("Lift"), lift(new TalonSRX(liftPort)) {

}

void Lift::InitDefaultCommand()
{
	SetDefaultCommand(new MoveLift());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
void Lift::liftMove(double power) {
	lift->Set(ControlMode::PercentOutput, power);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
Lift::~Lift() {
	if (lift != nullptr) {
		delete lift;
	}
}
