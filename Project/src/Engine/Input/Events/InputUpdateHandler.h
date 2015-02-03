#ifndef _INPUT_UPDATE_HANDLER_H
#define _INPUT_UPDATE_HANDLER_H

#include "InputUpdate.h"
#include "../../../Common/Events/EventHandler.h"
#include "../InputModel.h"

#include <iostream>

class InputUpdateHandler : public EventHandler {
public:
	InputUpdateHandler( InputModel & model ) : model{ model } {}
	static StringID GetID() {
		static auto table = StringTable::GetInstance();
		static auto id = table.GetStringID( "InputUpdateHandler" );
		return id;
	}
	void HandleEvent( Event & event ) {
		static auto id = InputUpdate::GetID();
		if ( event.GetID() == id ) {
			while ( model.HasCommands() ) {
				auto command = model.PopCommand();
				std::cout << command->GetKey() << std::endl;
			}
		}
	}
private:
	InputModel & model;
};

#endif
