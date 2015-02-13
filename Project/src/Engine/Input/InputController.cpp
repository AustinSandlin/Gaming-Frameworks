#include "InputController.h"

using namespace Input;

void InputController::handleKeyboardEvent( const char& key ) {
    Input::KeyboardEvent event( key, 0, 0 );
	kbqueue.push(event);
}

void InputController::handleMouseEvent( const int& x, const int& y ) {
    Input::MouseEvent event( 0, 0, x, y );
	mqueue.push(event);
}

void InputController::handleKeyboardInput() {
	while(!kbqueue.empty()) {
		std::cout << kbqueue.next().get_key() << std::endl;
        //game_controller.handleInputEvent(kbqueue.next().get_id());
		kbqueue.pop();
	}
}

void InputController::handleMouseInput() {
	while(!mqueue.empty()) {
		//Tell system this event was triggered.
	}
}