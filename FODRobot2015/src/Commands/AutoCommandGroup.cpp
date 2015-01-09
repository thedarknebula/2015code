// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoCommandGroup.h"
#include "driveAuto.h"

AutoCommandGroup::AutoCommandGroup() {
	printf("\n In AutoCommandGroup::AutoCommandGroup() ");

	//DriveAuto(side, fow, rot, yaw, time);
	AddSequential(new driveAuto(0.0, -0.3, 0.0, 0.0, 3));
	printf("\n Done AddSequential(new DriveAuto(0.0, -0.3, 0.0, 0.0, 0.3))");

	AddSequential(new driveAuto(0.3, 0.0, 0.0, 0.0, 3));
	printf("\n Done AddSequential(new DriveAuto(0.0, 0.4, 0.0, 0.0, 0.3)) ");

	AddSequential(new driveAuto(0.0, 0.3, 0.0, 0.0, 3));
	printf("\n Done AddSequential(new DriveAuto(0.5, 0.0, 0.0, 0.0, 0.3)) ");

	AddSequential(new driveAuto(-0.3, 0.0, 0.0, 0.0, 3));
	printf("\n Done AddSequential(new DriveAuto(0.5, 0.0, 0.0, 0.0, 0.3)) ");
}
