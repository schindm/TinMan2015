/*
 *
 *  Created on: Jan 13, 2015
 *      Author: MikeCaplan
 */
/*
 * OI.cpp
 *
 *  Created on: Jun 3, 2014
 *      Author: alex
 */

#include "OI.h"

#include "Commands/CommandRackExtend.h"
#include "Commands/CommandRackFlat.h"
#include "Commands/CommandRackRaise.h"
#include "Commands/CommandShovelDump.h"
#include "Commands/CommandShovelGround.h"
#include "Commands/CommandShovelHuman.h"
#include "Commands/CommandTestPneumatics.h"
#include "Commands/TestCommandGroup.h"

#include "RobotMap.h"


OI::OI() {
	stick= new Joystick(0);


    // Create some buttons
    JoystickButton* buttonA = new JoystickButton(stick, RobotMap::Controls::extendRack);
    JoystickButton* buttonB= new JoystickButton(stick, RobotMap::Controls::raiseRack);
    JoystickButton* buttonC= new JoystickButton(stick, RobotMap::Controls::flatRack);
    JoystickButton* buttonD = new JoystickButton(stick, RobotMap::Controls::groundShovel);
    JoystickButton* buttonE = new JoystickButton(stick, RobotMap::Controls::humanShovel);
    JoystickButton* buttonF = new JoystickButton(stick, RobotMap::Controls::dumpShovel);

    JoystickButton* buttonTest = new JoystickButton(stick, 12);
    buttonTest->WhenPressed(new CommandTestPneumatics());

    JoystickButton* buttonBigTest = new JoystickButton(stick, 1);
    buttonBigTest->WhenPressed(new TestCommandGroup());


    // Connect the buttons to commands
	buttonA->WhenPressed(new CommandRackExtend());
	buttonB->WhenPressed(new CommandRackRaise());
	buttonC->WhenPressed(new CommandRackFlat());
	buttonD->WhenPressed(new CommandShovelGround());
	buttonE->WhenPressed(new CommandShovelHuman());
	buttonF->WhenPressed(new CommandShovelDump());
}


Joystick* OI::GetJoystick() {
	return stick;
}



