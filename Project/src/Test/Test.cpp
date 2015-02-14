#include "../Engine/Input/InputController.h"
#include "../Engine/Game/GameController.h"
#include "../Common/Resources/Strings.h"
#include "../Engine/Object/ObjectController.h"

#include <iostream>

int main() {

	// Get the singleton for each of the following classes
	static auto& InputController = InputController::instance();
	static auto& GameController = GameController::instance();
	static auto& StringController = Strings::instance();
	static auto& ObjectController = ObjectController::instance();

	// ==========
	// Action Register Test
	// ==========

	GameController.registerInputAction(StringController.intern("w"), UP);
	GameController.registerInputAction(StringController.intern("a"), LEFT);
	GameController.registerInputAction(StringController.intern("s"), DOWN);
	GameController.registerInputAction(StringController.intern("d"), RIGHT);

	// ==========
	// Object Register Test
	// ==========
	ObjectController.registerGameObject(StringController.intern("BLOCK"), GameObject(StringController.intern("BLOCK"), 0, 1, true));

	// ==========
	// Input Test
	// ==========

	// Simulate a series of inputs and send them to the engine one letter at a time
	String input;
	std::cin >> input;
	for ( auto key : input ) {
		InputController.handleKeyboardEvent( key );
	}

	InputController.handleKeyboardInput();

	return 0;
}
