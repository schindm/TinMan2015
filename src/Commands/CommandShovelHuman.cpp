#include "CommandShovelHuman.h"
#include "../Utilities.h"
#include "../RobotMap.h"

CommandShovelHuman::CommandShovelHuman()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(shovel);
}

// Called just before this Command runs the first time
void CommandShovelHuman::Initialize()
{

	float angle = shovel->getPotentiometer();


	if(angle > RobotMap::Shovel::humanAngle) //past top
	{
		//start at half speed just in case
		shovel->setMotor(-.5);
	}
	else //before top
	{
		shovel->setMotor(.5);
	}
}

// Called repeatedly when this Command is scheduled to run
void CommandShovelHuman::Execute()
{
}


// Make this return true when this Command no longer needs to run execute()
bool CommandShovelHuman::IsFinished()
{
	float angle = shovel->getPotentiometer();

	//within a 5 degree threshold
	if(Utilities::isEqual(RobotMap::Shovel::humanAngle, angle, 2.0f))
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void CommandShovelHuman::End()
{
	shovel->setMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CommandShovelHuman::Interrupted()
{
	End();
}
