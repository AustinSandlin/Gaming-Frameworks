#include "InputController.h"

//Create and add a keyboard event for the character pushed to the keyboard queue.
void InputController::queueKeyboardEvent( unsigned char key, int x, int y ) {
    KeyboardEvent event( key, x, y );
	kbqueue.push(event);
}

//Create and add a mouse event for the location pushed to the mouse queue.
void InputController::queueMouseEvent( int button, int state, int x, int y ) {
    MouseEvent event( button, state, x, y );
	mqueue.push(event);
}

//Return the Queue of StringIDs that the input processor dealth with.
Queue<StringID> InputController::processInput() {
	Queue< StringID > ret;

	while(!kbqueue.empty()) {
        ret.push(kbqueue.next().get_id());
        kbqueue.pop();
	}

	while(!mqueue.empty()) {
		ret.push(mqueue.next().get_id());
        mqueue.pop();
	}

	return ret;
}