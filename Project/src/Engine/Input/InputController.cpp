#include "InputController.h"

//Create and add a keyboard event for the character pushed to the keyboard queue.
void InputController::handleKeyboardEvent( const char& key ) {
    KeyboardEvent event( key, 0, 0 );
	kbqueue.push(event);
}

//Create and add a mouse event for the location pushed to the mouse queue.
void InputController::handleMouseEvent( const int& x, const int& y ) {
    MouseEvent event( 0, 0, x, y );
	mqueue.push(event);
}

//Empty the queue and process each input. Basically, sent to the GameController.
void InputController::handleKeyboardInput() {
	while(!kbqueue.empty()) {
		std::cout << kbqueue.next().get_key() << std::endl;
        //game_controller.handleInputEvent(kbqueue.next().get_id());
		kbqueue.pop();
	}
}

//Same as the keyboard handler above.
void InputController::handleMouseInput() {
	while(!mqueue.empty()) {
		//Tell system this event was triggered.
	}
}