#include "../Common/Resources/Strings.h"

#include "../Engine/Game/GameController.h"
#include "../Engine/Object/ObjectController.h"

#include <iostream>
#include <sstream>

int main(int argc, char **argv) {

	static GameController& game_controller = GameController::instance();
	static ObjectController& object_controller = ObjectController::instance();
	static Strings& string_controller = Strings::instance();

	// ==========
	// Action Register Test
	// ==========

	game_controller.setupGameLoop(argc, argv);

	game_controller.registerInputAction(string_controller.intern("w"), UP);
	game_controller.registerInputAction(string_controller.intern("a"), LEFT);
	game_controller.registerInputAction(string_controller.intern("s"), DOWN);
	game_controller.registerInputAction(string_controller.intern("d"), RIGHT);
	game_controller.registerInputAction(string_controller.intern("\x1b"), QUIT);

	// ==========
	// Object Register Test
	// ==========

	for(int i = 0; i < 64; ++i) {
		for(int j = 0; j < 48; ++j) {
			std::stringstream ss;
            ss << "BACKGROUND_TILE_" << i << "_" << j;
            String name = ss.str();
			// String name = "BACKGROUND_TILE_" + std::to_string(i) + "_" + std::to_string(j);
			object_controller.registerBackgroundObject(string_controller.intern(name), BackgroundObject(string_controller.intern(name), i, j));
			if((i+j) % 2 == 1) {
				object_controller.registerObjectTexture(string_controller.intern(name), "../Images/green.bmp");
			}
			else {
				object_controller.registerObjectTexture(string_controller.intern(name), "../Images/yellow.bmp");
			}
		}
	}

	for(int i = 0; i < 32; ++i) {
		for(int j = 0; j < 24; ++j) {
			if(i == 0 || j == 0 || i == 31 || j == 23) {
				std::stringstream ss;
	            ss << "WALL_" << i << "_" << j;
	            String name = ss.str();
				// String name = "WALL_" + std::to_string(i) + "_" + std::to_string(j);
				object_controller.registerGameObject(string_controller.intern(name), GameObject(string_controller.intern(name), i, j, true));
				object_controller.registerObjectTexture(string_controller.intern(name), "../Images/red.bmp");
			}
		}
	}

	object_controller.registerGameObject(string_controller.intern("OBSTACLE_1"), GameObject(string_controller.intern("OBSTACLE_1"), 12, 10, true));
	object_controller.registerObjectTexture(string_controller.intern("OBSTACLE_1"), "../Images/black.bmp");
	object_controller.registerGameObject(string_controller.intern("OBSTACLE_2"), GameObject(string_controller.intern("OBSTACLE_2"), 18, 10, false));
	object_controller.registerObjectTexture(string_controller.intern("OBSTACLE_2"), "../Images/white.bmp");

	object_controller.registerHUDObject(string_controller.intern("HUD_ELEMENT_1"), HUDObject(string_controller.intern("HUD_ELEMENT_1"), 30, 22, false));
	object_controller.registerObjectTexture(string_controller.intern("HUD_ELEMENT_1"), "../Images/purple.bmp");

	object_controller.registerDebugObject(string_controller.intern("FPS_COUNTER"), HUDObject(string_controller.intern("FPS_COUNTER"), 990, 744, true));
	game_controller.registerDebugValue(string_controller.intern("FPS_COUNTER"), FPS);

	object_controller.registerPlayerObject(string_controller.intern("PLAYER1"), PlayerObject(string_controller.intern("PLAYER1"), 5, 5));
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_down.bmp");
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_up.bmp");
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_left.bmp");
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_right.bmp");

	// ==========
	// Game Loop Test
	// ==========

	//game_controller.setupGameLoop();
	game_controller.runGameLoop();

	return 0;
}
