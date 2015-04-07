#ifndef _SET_INTEGER_TRIGGER_H
#define _SET_INTEGER_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Game/GameController.h"

#include "../TriggerController.h"

class SetIntegerTrigger :

	public Command {

private:

	String name;
	Command * command;

public:

	SetIntegerTrigger( String name, Command * command ) {
		this->name = name;
		this->command = command;
	}

	~SetIntegerTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.setIntegerTrigger( name, command );
	}
};

Command * parseSetIntegerTrigger( StringStream & tokens ) {

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
	return new SetIntegerTrigger( name, command );
}

#endif
