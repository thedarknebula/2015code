#ifndef PneumaticsAutoClose_H
#define PneumaticsAutoClose_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Robot.h"

class PneumaticsAutoClose: public Command
{
public:
	PneumaticsAutoClose(bool left, bool right);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer* timer;
	double time_run;
	double time_timer;
	bool PneumaticsDone;
	double const PNEUMATIC_DELAY = 0.05;
	bool leftArm;
	bool rightArm;
};

#endif
