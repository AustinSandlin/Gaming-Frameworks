#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../Game/GameController.h"

#include "KeyboardQueue.h"
#include "MouseQueue.h"

#include <iostream>

class InputController : public Singleton< InputController >{

	private:

		friend class Singleton< InputController >;

		static GameController& game_controller;
		KeyboardQueue kbqueue;
		MouseQueue mqueue;

		InputController() {
			game_controller = GameController::instance();
		}

	public:
		void handleKeyboardEvent( const char& key );
		void handleMouseEvent( const int& x, const int& y );

		void handleKeyboardInput();
		void handleMouseInput();
};

#endif
