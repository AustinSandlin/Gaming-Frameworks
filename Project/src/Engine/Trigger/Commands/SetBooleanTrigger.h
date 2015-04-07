#ifndef _SET_BOOLEAN_TRIGGER_H
#define _SET_BOOLEAN_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Game/GameController.h"

#include "../TriggerController.h"

class SetBooleanTrigger :

	public Command {

private:

	String name;
	Command * command;

public:

	SetBooleanTrigger( String name, Command * command ) {
		this->name = name;
		this->command = command;
	}

	~SetBooleanTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.setBooleanTrigger( name, command );
	}
};

Command * parseSetBooleanTrigger( StringStream & tokens ) {

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
	return new SetBooleanTrigger( name, command );
}

#endif
