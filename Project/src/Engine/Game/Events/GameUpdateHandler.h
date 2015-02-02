#ifndef _GAME_UPDATE_EVENT_H
#define _GAME_UPDATE_EVENT_H

#include "../../../Common/Events/EventHandler.h"

class InputUpdateHandler : public EventHandler {
public:
	InputUpdateHandler( InputModel * model ) : model{ model } {}
	void HandleEvent( Event * event ) {
		auto id = StringTable::GetStringID( "GAME" );
		if ( event->GetSystemID() != id ) {
		}
		switch ( event->GetEventID() ) {
		}
	}
private:
	InputModel * model;
};

#endif
