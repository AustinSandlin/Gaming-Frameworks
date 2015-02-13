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
		KeyboardQueue kbqueue;
		MouseQueue mqueue;

		InputController() {
		}

	public:
		void handleKeyboardEvent( const KeyboardEvent& event );
		void handleMouseEvent( const MouseEvent& event );

		void handleKeyboardInput();
		void handleMouseInput();
	};
}

#endif
