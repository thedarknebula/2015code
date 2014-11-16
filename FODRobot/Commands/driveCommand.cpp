//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.


#include "driveCommand.h"
#include <math.h>

const float PI = 3.14159;


//Setting up variables
float XAxis;
float YAxis;
float RotateAxis;
float YAxis_Calc;

float IMU_Yaw;
float GyroAngleRads;

bool isCalibrating;
bool isInit;


driveCommand::driveCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveBaseSub);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void driveCommand::Initialize() {
	printf("Initialize driveCommand\n");
	//Setting up variables and IMU
	//This makes sure when we enable the robot, the joystick values are already pointing forward. 
	XAxis = 0;
	YAxis = 0;
	RotateAxis = 0;
	YAxis_Calc = 0;
	
	IMU_Yaw = 0;
    GyroAngleRads = 0;
	
	isCalibrating = true;
	
	isCalibrating = Robot::driveBaseSub->pRobot_IMU->IsCalibrating();
	if(!isCalibrating) 
		{
		Wait(0.3);
		}
	Robot::driveBaseSub->pRobot_IMU->ZeroYaw();
		
}

// Called repeatedly when this Command is scheduled to run
void driveCommand::Execute() {
	printf("i am running the drive command execute!\n");
	SmartDashboard::PutNumber("Angle of Robot", Robot::driveBaseSub->pRobot_IMU->GetYaw());
	XAxis = Robot::oi->getJoystick1()->GetRawAxis(1);
	YAxis = Robot::oi->getJoystick1()->GetRawAxis(2);
	RotateAxis = Robot::oi->getJoystick1()->GetRawAxis(4);
	
	//Sets up deadbands (this gets rid of the robot moving very slowly
	//even when you are not touching the joystick. Because the joystick
	//is never really at zero it is at for example 0.0389583. This makes
	//sure every joystick is in the range of -0.20 to 0.20 and if it is set all
	//the axis to zero, if not send the current value to the MechDrive function.
	
	//Also squares the values which increases sensitivity, and (mostly) blends out
	// the discontinuity you would have with just the dead band (there's no step from 0 to .2, 
	//  the lowest value is 0 to .04 now.
	
	if(XAxis < 0.20 && XAxis > -0.20)
	{
		XAxis = 0;
	}
	else 
	{
		XAxis = XAxis * fabs(XAxis);
	}
	
	if(YAxis < 0.20 && YAxis > -0.20)
	{
		YAxis = 0;
	}
	else 
	{
		YAxis = YAxis * fabs(YAxis);
	}
	if(RotateAxis < 0.20 && RotateAxis > -0.20)
	{
		RotateAxis = 0;
	}
	else 
	{
		RotateAxis = RotateAxis * fabs(RotateAxis);
	}
	
	SmartDashboard::PutNumber("JoyX", XAxis);
	SmartDashboard::PutNumber("JoyY", YAxis);
	SmartDashboard::PutNumber("JoyRot", RotateAxis);
	
	//Read current robot orientation angle measured from starting position=0 degrees
	IMU_Yaw = Robot::driveBaseSub->pRobot_IMU->GetYaw();
	
	//Sends XAxis, YAxis, and RotateAxis to MechDrive function in DriveBaseSub.cpp
	Robot::driveBaseSub->MechDrive(XAxis,YAxis,RotateAxis,IMU_Yaw);
}

// Make this return true when this Command no longer needs to run execute()
bool driveCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void driveCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void driveCommand::Interrupted() {

}
