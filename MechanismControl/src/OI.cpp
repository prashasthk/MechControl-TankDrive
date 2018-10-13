/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "Commands/TankDrive.h"


OI::OI() : driveStickLeft(new Joystick(joystickleftPort)), driveStickRight(new Joystick(joystickrightPort)) {

	// Process operator interface input here.
}
Joystick* OI::getDriveStickLeft() {
	return driveStickLeft;
}
Joystick*OI::getDriveStickRight() {
	return driveStickRight;
}
