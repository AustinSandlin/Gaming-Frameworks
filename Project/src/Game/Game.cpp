#include "../Engine/Game/GameController.h"

#include <thread>
#include <chrono>

int main( int argc, char ** argv ) {

	// 
	if ( argc != 2 ) {
		cout << "Usage: main.exe filename" << endl;
		exit(1);
	}

	// 
	static GameController & game_controller = GameController::instance();

	// 
	game_controller.setupGameLoop( argc, argv );
	game_controller.runCommandFile( argv[1] );
	game_controller.runGameLoop();


    std::this_thread::sleep_for(std::chrono::seconds(10));

	// 
	return 0;
}
