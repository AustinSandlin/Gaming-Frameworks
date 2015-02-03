#ifndef _INPUT_UPDATE_HANDLER_H
#define _INPUT_UPDATE_HANDLER_H

#include "InputUpdate.h"
#include "../../../Common/Events/EventHandler.h"
#include "../InputModel.h"

#include <iostream>

class InputUpdateHandler : public EventHandler {
public:
	InputUpdateHandler() {}
	static StringID GetID() {
		static auto & table = StringTable::GetInstance();
		static auto id = table.GetStringID( "InputUpdateHandler" );
		return id;
	}
	void HandleEvent( Event * event ) {
		static auto & model = InputModel::GetInstance();
		static auto id = InputUpdate::GetID();
		if ( event->GetID() == id ) {
			std::cout << "Keys Pressed: ";
			while ( model.HasCommands() ) {
				auto command = model.NextCommand();
				std::cout << "<" << command->GetKey() << "> ";
				model.PopCommand();
			}
			std::cout << std::endl;
		}
	}
};

#endif
