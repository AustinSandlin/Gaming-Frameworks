#ifndef _INPUT_COMMAND_HANDLER_H
#define _INPUT_COMMAND_HANDLER_H

#include "InputCommand.h"
#include "../../../Common/Events/EventHandler.h"
#include "../InputModel.h"

class InputCommandHandler : public EventHandler {
public:
	InputCommandHandler( InputModel & model ) : model{ model } {}
	static StringID GetID() {
		static auto table = StringTable::GetInstance();
		static auto id = table.GetStringID( "InputCommandHandler" );
		return id;
	}
	void HandleEvent( Event & event ) {
		static auto id = InputCommand::GetID();
		if ( event.GetID() == id ) {
			model.PushCommand( ( InputCommand * ) & event );
		}
	}
private:
	InputModel & model;
};

#endif
