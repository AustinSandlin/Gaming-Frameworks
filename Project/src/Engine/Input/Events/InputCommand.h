/*
void keyboard( unsigned char key, int x, int y ) {
	static auto controller = InputController::GetInstance();
	auto event = new InputCommand( key );
	controller.HandleEvent( event );
}
*/

#ifndef _INPUT_COMMAND_H
#define _INPUT_COMMAND_H

#include "../../../Common/Events/Event.h"
#include "../../../Common/Strings/StringTable.h"

class InputCommand : public Event {
public:
	InputCommand( unsigned char key ) :  Event( GetID() ), key{ key } {}
	static StringID GetID() {
		static auto & table = StringTable::GetInstance();
		static auto id = table.GetStringID( "InputCommand" );
		return id;
	}
	unsigned char GetKey() { return key; }
private:
	unsigned char key;
};

#endif
