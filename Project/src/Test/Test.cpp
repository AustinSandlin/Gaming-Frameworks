#include "../Common/Systems/Strings.h"

#include "../Engine/Input/Controller.h"
#include "../Engine/Input/View.h"

#include <iostream>

int main() {

	// Get the singleton for each of the following classes
	static auto & controller = Input::Controller::instance();
	static auto & view = Input::View::instance();
	static auto & strings = Strings::instance();

	// ==========
	// First Test
	// ==========

	// Create two objects: a & b
	auto a = strings.intern( "Hello" );
	auto b = strings.intern( "World" );

	// Attach input queues to these objects so that they listen for input
	controller.handle( Object::AddProperty< Input::KeyboardActionQueue >( a ) );
	controller.handle( Object::AddProperty< Input::KeyboardActionQueue >( b ) );

	// Simulate a series of inputs and send them to the engine one key at a time
	String input;
	std::cin >> input;
	for ( auto key : input ) {
		Input::KeyboardAction event( key, 0, 0 );
		controller.handle( Input::PushAction< Input::KeyboardAction >( event ) );
	}

	// Empty the queues
	auto & keyboards = view.get_keyboard_action_queues();
	for ( auto it : keyboards ) {

		// Lookup and print the string identifying the current queue
		std::cout << strings.lookup( it.get_id() ) << ":" << std::endl;

		// Dequeue and print each entry in the current queue
		auto & queue = it.get_value();
		while ( !queue.empty() ) {
			auto & input = queue.next();

			/*
			if ( key_map.has( it.get_id() ) ) {
				auto & it2 = key_map.get( it.get_id() );
				KeyMap km = it2.get_value();

				enum GAME_INPUT {
					INPUT_1,
					INPUT_2
				};

				switch ( km.translate( input.get_key() ) ) {
					case INPUT_1:
						physics_controller.handle(  );
					case INPUT_2:

				}
			}
			*/

			std::cout << input.get_key() << std::endl;
			controller.handle( Input::PopAction< Input::KeyboardAction >( it.get_id() ) );
		}
	}

	// ===========
	// Second Test
	// ===========

	// Try removing object a
	controller.handle( Object::RemoveProperty< Input::KeyboardActionQueue >( a ) );

	// Simulate a series of inputs and send them to the engine one key at a time
	std::cin >> input;
	for ( auto key : input ) {
		Input::KeyboardAction event( key, 0, 0 );
		controller.handle( Input::PushAction< Input::KeyboardAction >( event ) );
	}

	// Empty the remaining queue
	for ( auto it : keyboards ) {

		// Lookup and print the string identifying the current queue
		std::cout << strings.lookup( it.get_id() ) << ":" << std::endl;

		// Dequeue and print each entry in the current queue
		auto & queue = it.get_value();
		while ( !queue.empty() ) {
			auto & input = queue.next();
			std::cout << input.get_key() << std::endl;
			controller.handle( Input::PopAction< Input::KeyboardAction >( it.get_id() ) );
		}
	}

	return 0;
}
