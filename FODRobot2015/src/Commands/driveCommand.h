// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class driveCommand: public Command {
public:
	driveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual float RotateToAngleDrive(float Angle, float Speed);
private:
	float ANGLE_TOLERANCE; // Tolerance in degrees on either side of set angle
	float DRIVE_ANGLE; // Only causing drive spins in this command - it doesn't need to know angle.
	float DRIVE_X; // used for translation magnitude to drive command - not used - stays 0
	float DRIVE_Y; // used for translation magnitude to drive command - not used - stays 0
	float ROTATE_LOOP_CHECK; //checks for iterations through loop. Change later depending on robot

	bool ButtonAPressed; //rotate to 180
	bool ButtonBPressed; //rotate to 135
	bool ButtonXPressed; //rotate to -135
	bool ButtonYPressed; //rotate to 0

	float SetAngle; // Saves the commanded go-to angle functional parameter passed in.
	float SetInitAngle; // Initial Set Angle for Rotation

	float SetSpeed; // Current spin speed for piece wise linear angle from set point distance
	float MaxScalingSpeed; // Scales SetSpeed by overall scaling factor (used to slow down whole spin)

	//Default values for drive command - joystick overrides these
	float XAxis;
	float YAxis ;
	float RotateAxis;

	float DriverRotateAxisOverride; //Driver override AutoRotation value

	float IMU_Yaw;  //Yaw value from IMU and scaled value to eliminate
	float IMU_Scaled; // Translated to a non-wrapping scale (-180 to 180 -> 820 to 1180)
	float SetAngleScaled; // Converted value of the Commanded Set Angle to linear scale.

	int SpinDirection;  // Sets pin direction: 1=Clockwise from robot top, -1=CCW
	float RotCmd; //Calculated rotation speed to command

	//Assume we don't need the robot to spin until proven via measurement.
	bool TooFarCW; // Robot is further CW than set point: needs to spin CCW
	bool TooFarCCW; //Robot is further CCW than set point: needs to spin CW

	float DegreesToSetPoint; //Number of degrees from current angle to set point
	float DegreesToSetPointAbs; //absolute value of DegreesToSetPoint

	//Persistence of measurements of current angle to determine if system has stopped moving, overshooting
	int TimesThroughLoop;

	float AutoRotCmd; // Rotate command from AutoRotate calculator

	bool AutoRotDone; //Rotate command is done

	bool slow_button; //button to slow drive command
	PowerDistributionPanel* pdp;
	float amponmotor;
	float speedMulti;
};

#endif
