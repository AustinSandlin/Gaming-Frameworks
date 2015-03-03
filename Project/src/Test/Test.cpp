#include "../Common/Resources/Strings.h"

#include "../Engine/Audio/AudioController.h"
#include "../Engine/Game/GameController.h"
#include "../Engine/Object/ObjectController.h"
#include "../Engine/Loader/Loader.h"

#include <iostream>
#include <sstream>

int main(int argc, char **argv) {

	// LOADER TESTS


	static AudioController& audio_controller = AudioController::instance();
	static GameController& game_controller = GameController::instance();


	game_controller.setupGameLoop(argc, argv);

	Loader loader;
	loader.loadLevel("test.txt");

	game_controller.runGameLoop();

	
	/*
	static AudioController& audio_controller = AudioController::instance();
	static GameController& game_controller = GameController::instance();
	static ObjectController& object_controller = ObjectController::instance();
	static Strings& string_controller = Strings::instance();

	// ==========
	// Load Sounds
	// ==========

	try {
	    audio_controller.addSound( "collision", "../Sounds/buzzer.wav" );
	    audio_controller.addSound( "background", "../Sounds/elevator.wav");
	}
	catch ( const char * error ) {
		cout << error << endl;
	}

	// ==========
	// Action Register Test
	// ==========

	game_controller.setupGameLoop(argc, argv);

	game_controller.registerInputAction(string_controller.intern("w"), MOVE_UP);
	game_controller.registerInputAction(string_controller.intern("a"), MOVE_LEFT);
	game_controller.registerInputAction(string_controller.intern("s"), MOVE_DOWN);
	game_controller.registerInputAction(string_controller.intern("d"), MOVE_RIGHT);
	game_controller.registerInputAction(string_controller.intern("\x1b"), QUIT);

	// ==========
	// Object Register Test
	// ==========

	for(int i = 0; i < 32; ++i) {
		for(int j = 0; j < 24; ++j) {
			std::stringstream ss;
            ss << "BACKGROUND_TILE_" << i << "_" << j;
            String name = ss.str();
			// String name = "BACKGROUND_TILE_" + std::to_string(i) + "_" + std::to_string(j);
			object_controller.registerBackgroundObject(string_controller.intern(name), BackgroundObject(string_controller.intern(name), i*32, j*32, 32, 32));
			if((i+j) % 2 == 1) {
				object_controller.registerObjectTexture(string_controller.intern(name), "../Images/green_alpha.bmp");
			}
			else {
				object_controller.registerObjectTexture(string_controller.intern(name), "../Images/yellow_alpha.bmp");
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
				object_controller.registerGameObject(string_controller.intern(name), GameObject(string_controller.intern(name), i*32, j*32, 32, 32, true));
				object_controller.registerObjectTexture(string_controller.intern(name), "../Images/red_alpha.bmp");
			}
		}
	}

	object_controller.registerGameObject(string_controller.intern("OBSTACLE_1"), GameObject(string_controller.intern("OBSTACLE_1"), 12*32, 10*32, 32, 32, true));
	object_controller.registerObjectTexture(string_controller.intern("OBSTACLE_1"), "../Images/black_alpha.bmp");
	object_controller.registerGameObject(string_controller.intern("OBSTACLE_2"), GameObject(string_controller.intern("OBSTACLE_2"), 18*32, 10*32, 32, 32, false));
	object_controller.registerObjectTexture(string_controller.intern("OBSTACLE_2"), "../Images/white_alpha.bmp");

	object_controller.registerHUDObject(string_controller.intern("HUD_ELEMENT_1"), HUDObject(string_controller.intern("HUD_ELEMENT_1"), 30*32, 22*32, 32, 32, false));
	object_controller.registerObjectTexture(string_controller.intern("HUD_ELEMENT_1"), "../Images/purple_circle.bmp");

	object_controller.registerDebugObject(string_controller.intern("FPS_COUNTER"), HUDObject(string_controller.intern("FPS_COUNTER"), 990, 744, 64, 64, true));
	game_controller.registerDebugValue(string_controller.intern("FPS_COUNTER"), FPS);

	object_controller.registerPlayerObject(string_controller.intern("PLAYER1"), PlayerObject(string_controller.intern("PLAYER1"), 5*32, 5*32, 32, 32));
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_down_alpha.bmp");
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_up_alpha.bmp");
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_left_alpha.bmp");
	object_controller.registerObjectTexture(string_controller.intern("PLAYER1"), "../Images/player_right_alpha.bmp");

	object_controller.registerAIObject(string_controller.intern("AI1"), AIObject(string_controller.intern("AI1"), 10*32, 10*32, 32, 32, WANDER));
	object_controller.registerObjectTexture(string_controller.intern("AI1"), "../Images/red_alpha.bmp");

	// ==========
	// Game Loop Test
	// ==========

	//game_controller.setupGameLoop();
	game_controller.runGameLoop();
	*/

	return 0;
}
