#include "../Common/Resources/Strings.h"

#include "../Engine/Game/GameController.h"
#include "../Engine/Object/ObjectController.h"

#include <iostream>

int main(int argc, char **argv) {

	static GameController& game_controller = GameController::instance();
	static ObjectController& object_controller = ObjectController::instance();
	static Strings& string_controller = Strings::instance();

	// ==========
	// Action Register Test
	// ==========

	game_controller.registerInputAction(string_controller.intern("w"), UP);
	game_controller.registerInputAction(string_controller.intern("a"), LEFT);
	game_controller.registerInputAction(string_controller.intern("s"), DOWN);
	game_controller.registerInputAction(string_controller.intern("d"), RIGHT);
	game_controller.registerInputAction(string_controller.intern("\x1b"), QUIT);

	// ==========
	// Object Register Test
	// ==========
	object_controller.registerGameObject(string_controller.intern("BLOCK"), GameObject(string_controller.intern("BLOCK"), 0, 1, true));

	// ==========
	// Game Loop Test
	// ==========

	//game_controller.setupGameLoop();
	game_controller.setupGameLoop(argc, argv);
	game_controller.runGameLoop();

	return 0;
}
