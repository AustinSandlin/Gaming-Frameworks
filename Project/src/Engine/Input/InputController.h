#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "../../Common/Base/Queue.h"

#include "Events/KeyboardEvent.h"
#include "Events/MouseEvent.h"

#include <iostream>
#include <map>

using namespace std;

class InputController : public Singleton< InputController >{

	private:

		friend class Singleton< InputController >;
		// Input queues for storing events to process all at once.
		//Queue< KeyboardEvent > kbqueue;
		map<KeyboardEvent, bool> key_flags;

		Queue< MouseEvent > mqueue;


		InputController() {
		}

	public:
		// These are the functions to be used in callbacks.
		void queueKeyboardEvent( unsigned char key, int x, int y );
		void dequeueKeyboardEvent( unsigned char key, int x, int y );
		void queueMouseEvent( int button, int state, int x, int y );

		/* This will return all the StringIDs of the keys pressed. The game
		 * controller will take those strings and call things as necessary.
		 */
		Queue<StringID> queueInputs();
};

#endif
