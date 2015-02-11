#include "../Common/Tables/StringTable.h"

#include "../Engine/Input/InputController.h"
#include "../Engine/Input/Tables/InputQueueTable.h"

#include <iostream>

int main() {

	// Get the singleton for each of the following classes
	static auto & controller = InputController::instance();
	static auto & queues = InputQueueTable::instance();
	static auto & strings = StringTable::instance();
	static auto & objects = ObjectTable::instance();

	// ==========
	// First Test
	// ==========

	// Create two objects: a & b
	auto a = strings.intern( "Hello" );
	auto b = strings.intern( "World" );

	// Attach input queues to these objects so that they listen for input
	queues.add( a, InputQueue() );
	queues.add( b, InputQueue() );

	// Simulate a series of inputs and send them to the engine one key at a time
	String input;
	std::cin >> input;
	for ( auto key : input ) {
		controller.handle( InputUpdate( key ) );
	}

	// Empty the queues
	for ( auto it : queues ) {

		// Lookup and print the string identifying the current queue
		std::cout << strings.lookup( it.id() ) << ":" << std::endl;

		// Dequeue and print each entry in the current queue
		auto & queue = it.value();
		while ( !queue.empty() ) {
			std::cout << queue.dequeue() << std::endl;
		}
	}

	// ==========
	// First Test
	// ==========

	// Try removing object a
	objects.remove( a );

	// Simulate a series of inputs and send them to the engine one key at a time
	std::cin >> input;
	for ( auto key : input ) {
		controller.handle( InputUpdate( key ) );
	}

	// Empty the queues
	for ( auto it : queues ) {

		// Lookup and print the string identifying the current queue
		std::cout << strings.lookup( it.id() ) << ":" << std::endl;

		// Dequeue and print each entry in the current queue
		auto & queue = it.value();
		while ( !queue.empty() ) {
			std::cout << queue.dequeue() << std::endl;
		}
	}


	return 0;
}
