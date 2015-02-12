/*
#include "../Engine/Input/Controller.h"

class OpenGL {

public:

	OpenGL() {
		glutDisplayFunc( display );
		glutKeyboardFunc( keyboard );
		glutMouseFunc( mouse );
	}
	static void display() {
	}
	static void keyboard( unsigned char key, int x, int y ) {
		static auto & controller = Input::Controller::instance();
		Input::KeyboardAction action( key, x, y );
		Input::PushAction< Input::KeyboardAction > event( action );
		controller.handle( event );
	}
	static void mouse( int button, int state, int x, int y ) {
		static auto & controller = Input::Controller::instance();
		Input::MouseAction action( button, state, x, y );
		Input::PushAction< Input::MouseAction > event( action );
		controller.handle( event );
	}
};
*/
