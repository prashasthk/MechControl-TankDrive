/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Utilities/WVPIDController.h>
#include "OI.h"
#include "Subsystems/Lift.h"
#include "../Robot.h"

class AutoMoveLift : public frc::Command {
private:
double target;
double liftKp = 0.1;
double liftKi = 0;
double liftKd = 0;
double power = 0;

WVPIDController * liftPID;

public:
	AutoMoveLift(double setpoint);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

