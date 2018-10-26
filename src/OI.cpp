/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "Commands/TankDrive.h"
#include "Commands/GroupedDriving.h"
#include "Commands/ResetLift.h"
#include "WPILib.h"

OI::OI() : driveStickLeft(new Joystick(joystickleftPort)),
driveStickRight(new Joystick(joystickrightPort)),
liftStick(new Joystick(joystickliftPort)),
groupedDriveButton(new JoystickButton(driveStickLeft, LEFT_BUTTON_PORT)),
resetLiftButton(new JoystickButton(driveStickLeft, RESET_LIFT_PORT))
{
	groupedDriveButton->WhenPressed(new GroupedDriving(0.5, 0.5));
	resetLiftButton->WhenPressed(new ResetLift());
}
Joystick* OI::getDriveStickLeft() {
	return driveStickLeft;
}
Joystick*OI::getDriveStickRight() {
	return driveStickRight;
}
Joystick*OI::getLiftStick() {
	return liftStick;
}

