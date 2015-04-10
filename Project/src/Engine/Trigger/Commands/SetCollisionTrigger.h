#ifndef _SET_COLLISION_TRIGGER_H
#define _SET_COLLISION_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Game/GameController.h"

#include "../TriggerController.h"

class SetCollisionTrigger :

	public Command {

private:

	String name;
	Command * command;

public:

	SetCollisionTrigger( String name, Command * command ) {
		this->name = name;
		this->command = command;
	}

	~SetCollisionTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.setCollisionTrigger( name, command );
	}
};

Command * parseSetCollisionTrigger( StringStream & tokens ) {

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
	return new SetCollisionTrigger( name, command );
}

#endif
