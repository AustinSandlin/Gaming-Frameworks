#include "../Engine/Input/InputController.h"
#include "../Engine/Game/GameController.h"
#include "../Common/Resources/Strings.h"

#include <iostream>

int main() {

	// Get the singleton for each of the following classes
	static auto& InputController = InputController::instance();
	static auto& GameController = GameController::instance();
	static auto& StringController = Strings::instance();

	// ==========
	// Action Register Test
	// ==========

	GameController.registerInputAction(StringController.intern("w"), UP);
	GameController.registerInputAction(StringController.intern("a"), LEFT);
	GameController.registerInputAction(StringController.intern("s"), DOWN);
	GameController.registerInputAction(StringController.intern("d"), RIGHT);

	// ==========
	// Input Test
	// ==========

	// Simulate a series of inputs and send them to the engine one word at a time
	String input;
	std::cin >> input;
	for ( auto key : input ) {
		InputController.handleKeyboardEvent( key );
	}

	InputController.handleKeyboardInput();

	return 0;
}
