#include "InputController.h"

//Create and add a keyboard event for the character pushed to the keyboard queue.
void InputController::queueKeyboardEvent( unsigned char key, int x, int y ) {
    KeyboardEvent event( key, x, y );

	bool found = false;

    map<KeyboardEvent, bool>::iterator it = key_flags.begin();
    while(it != key_flags.end() && !found) {
        if((it->first).getID() == event.getID()) {
            it->second = true;
            found = true;
        }
        ++it;
    }

    if(!found) {
        key_flags[event] = true;
    }
}

//Create and add a keyboard event for the character pushed to the keyboard queue.
void InputController::dequeueKeyboardEvent( unsigned char key, int x, int y ) {
    KeyboardEvent event( key, x, y );

    bool found = false;

    map<KeyboardEvent, bool>::iterator it = key_flags.begin();
    while(it != key_flags.end() && !found) {
        if((it->first).getID() == event.getID()) {
            it->second = false;
            found = true;
        }
        ++it;
    }
}

//Create and add a mouse event for the location pushed to the mouse queue.
void InputController::queueMouseEvent( int button, int state, int x, int y ) {
    MouseEvent event( button, state, x, y );
	//mqueue.push(event);
}

//Return the Queue of StringIDs that the input processor dealth with.
Queue<StringID> InputController::queueInputs() {
	Queue< StringID > ret;

    map<KeyboardEvent, bool>::iterator it = key_flags.begin();
    while(it != key_flags.end()) {
        if(it->second == true) {
            ret.push((it->first).getID());
        }
        ++it;
    }

	while(!mqueue.empty()) {
		ret.push(mqueue.next().getID());
        mqueue.pop();
	}

	return ret;
}