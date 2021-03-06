#include "CommandBase.h"
#include "Subsystems/RackMotor.h"
#include "Commands/Scheduler.h"
#include "Utilities.h"

// Initialize a single static instance of all of your subsystems to NULL
RackMotor* CommandBase::rackMotor = NULL;
OI* CommandBase::oi = NULL;
DriveTrain* CommandBase::driveTrain = NULL;
Shovel* CommandBase::shovel = NULL;
Camera* CommandBase::camera = NULL;
TestPneumatics* CommandBase::pneumatics = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

CommandBase::~CommandBase()
{
	SAFE_DELETE(rackMotor);
	SAFE_DELETE(oi);
	SAFE_DELETE(driveTrain);
	SAFE_DELETE(shovel);
	SAFE_DELETE(camera);
	SAFE_DELETE(pneumatics);
}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	rackMotor = new RackMotor();
	driveTrain = new DriveTrain();
	shovel = new Shovel();
	camera = new Camera();
	pneumatics = new TestPneumatics();
	oi = new OI();
}
