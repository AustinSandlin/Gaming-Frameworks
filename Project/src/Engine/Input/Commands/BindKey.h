#ifndef _BIND_KEY_H
#define _BIND_KEY_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Game/GameController.h"

class BindKey :

	public Command {

private:

	String key;
	InputAction action;

public:

	BindKey( String key, InputAction action ) {
		this->key = key;
		this->action = action;
	}

	~BindKey() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static GameController & game_controller = GameController::instance();

		// 
		StringID id = strings.intern( key );
		game_controller.registerInputAction( id, action );
	}
};

Command * parseBindKey( StringStream & tokens ) {

	// 
	String key, text;
	InputAction action;

	// 
	tokens >> key;
	if ( key.size() != 1 ) {
		return NULL;
	}

	// 
	tokens >> text;
	if ( text == "up" ) {
		action = MOVE_UP;
	}
	else if ( text == "down") {
		action = MOVE_DOWN;
	}
	else if ( text == "left" ) {
		action = MOVE_LEFT;
	}
	else if ( text == "right" ) {
		action = MOVE_RIGHT;
	}
	else if ( text == "quit" ) {
		action = QUIT;
	}
	else if ( text == "attack" ) {
		action = ATTACK;
	}
	else {
		return NULL;
	}

	// 
	return new BindKey( key, action );
}

#endif
