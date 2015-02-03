#ifndef _INPUT_UPDATE_HANDLER_H
#define _INPUT_UPDATE_HANDLER_H

class InputUpdateHandler : public EventHandler {
public:
	InputUpdateHandler( InputModel & model ) : model{ model } {}
	void HandleEvent( Event & event ) {
		static auto table = StringTable::GetInstance();
		static auto id = table.GetStringID( "InputUpdateHandler" );
		if ( event.GetID() == id ) {
			// Do stuff...
		}
	}
	const static 
private:
	InputModel & model;
};

#endif
