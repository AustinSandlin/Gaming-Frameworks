#ifndef _SET_FLOAT_TRIGGER_H
#define _SET_FLOAT_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Game/GameController.h"

#include "../TriggerController.h"


#include <iostream>
using namespace std;

class SetFloatTrigger :

	public Command {

private:

	String name;
	Command * command;

public:

	SetFloatTrigger( String name, Command * command ) {
		this->name = name;
		this->command = command;
	}

	~SetFloatTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.setFloatTrigger( name, command );
	}
};

Command * parseSetFloatTrigger( StringStream & tokens ) {

	// 
	static GameController & game_controller = GameController::instance();

	// 
	String name;
	Command * command;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	command = game_controller.parseCommand( tokens );
	if ( command == NULL ) {
		return NULL;
	}

	// 
	return new SetFloatTrigger( name, command );
}

#endif
