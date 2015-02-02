#ifndef _INPUT_UPDATE_HANDLER_H
#define _INPUT_UPDATE_HANDLER_H

class InputUpdateHandler : public EventHandler {
public:
	InputUpdateHandler( InputModel * model ) : model{ model } {}
	void HandleEvent( Event * event ) {
		if ( event->GetSystemID() != INPUT ) {
		}
		switch ( event->GetEventID() ) {
		}
	}
private:
	InputModel * model;
};

#endif
