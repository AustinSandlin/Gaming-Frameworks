#include "../Engine/Input/InputController.h"
#include "../Common/Resources/Strings.h"

#include <iostream>

int main() {

	// Get the singleton for each of the following classes
	static auto & controller = Input::InputController::instance();
	static auto & strings = Strings::instance();

	// ==========
	// First Test
	// ==========

	// Simulate a series of inputs and send them to the engine one word at a time
	String input;
	std::cin >> input;
	for ( auto key : input ) {
		Input::KeyboardEvent event( key, 0, 0 );
		controller.handleKeyboardEvent( event );
	}

	controller.handleKeyboardInput();

	return 0;
}
