#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"

#include "KeyboardQueue.h"
#include "MouseQueue.h"

#include <iostream>

namespace Input {

	class InputController : public Singleton< InputController >{

	private:

		friend class Singleton< InputController >;
		//static GameController& game_controller = Game::GameController::instance();
		KeyboardQueue kbqueue;
		MouseQueue mqueue;

		KeyboardQueueSchedule kbschedule;

		InputController() {
		}

	public:
		void handleKeyboardEvent( const char& key );
		void handleMouseEvent( const int& x, const int& y );

		void handleKeyboardInput();
		void handleMouseInput();

		void scheduleKeyboardEvent( const char& key, const long &time );

		void update() {
			while ( kbschedule.empty() )
				handleKeyboardEvent( key );
			}
		}
	};
}

#endif
