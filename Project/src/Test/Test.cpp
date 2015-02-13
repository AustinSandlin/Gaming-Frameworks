#include "../Engine/Input/InputController.h"

#include <iostream>

int main() {

	// Get the singleton for each of the following classes
	static auto & controller = Input::InputController::instance();

	// ==========
	// First Test
	// ==========

	// Simulate a series of inputs and send them to the engine one word at a time
	String input;
	std::cin >> input;
	for ( auto key : input ) {
		controller.handleKeyboardAction( key );
	}

	controller.handleKeyboardInput();

	return 0;
}
