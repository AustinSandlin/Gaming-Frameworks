#include "InputController.h"

using namespace Input;

void InputController::handleKeyboardEvent( const KeyboardEvent& event) {
	kbqueue.push(event);
}

void InputController::handleMouseEvent( const MouseEvent& event) {
	mqueue.push(event);
}

void InputController::handleKeyboardInput() {
	while(!kbqueue.empty()) {
		std::cout << kbqueue.next().get_key() << std::endl;
		kbqueue.pop();
	}
}

void InputController::handleMouseInput() {
	while(!mqueue.empty()) {
		//Tell system this event was triggered.
	}
}