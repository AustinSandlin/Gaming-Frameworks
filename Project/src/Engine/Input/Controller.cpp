#include "Model.h"

using namespace Input;

void Controller::handle( const Object::AddProperty< KeyboardActionQueue > & event ) {
	
	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & keyboards = model.get_table< KeyboardActionQueue >();

	// 
	keyboards.add( event.get_id(), KeyboardActionQueue() );
}

void Controller::handle( const Object::AddProperty< MouseActionQueue > & event ) {
	
	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & mice = model.get_table< MouseActionQueue >();

	// 
	mice.add( event.get_id(), MouseActionQueue() );
}

void Controller::handle( const Object::RemoveProperty< KeyboardActionQueue > & event ) {
	
	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & keyboards = model.get_table< KeyboardActionQueue >();

	// 
	keyboards.remove( event.get_id() );
}

void Controller::handle( const Object::RemoveProperty< MouseActionQueue > & event ) {
	
	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & mice = model.get_table< MouseActionQueue >();

	// 
	mice.remove( event.get_id() );
}

void Controller::handle( const Object::RemoveProperties & event ) {
	
	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & keyboards = model.get_table< KeyboardActionQueue >();
	static auto & mice = model.get_table< MouseActionQueue >();
	
	// 
	keyboards.remove( event.get_id() );
	mice.remove( event.get_id() );
}

void Controller::handle( const PushAction< KeyboardAction > & event ) {

	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & keyboards = model.get_table< KeyboardActionQueue >();

	// 
	for ( auto & it : keyboards ) {
		auto & keyboard = it.get_value();
		keyboard.push( event.get_action() );
	}
}

void Controller::handle( const PushAction< MouseAction > & event ) {

	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & mice = model.get_table< MouseActionQueue >();

	// 
	for ( auto & it : mice ) {
		auto & mouse = it.get_value();
		mouse.push( event.get_action() );
	}
}

void Controller::handle( const PopAction< KeyboardAction > & event ) {

	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & keyboards = model.get_table< KeyboardActionQueue >();

	// 
	if ( keyboards.has( event.get_id() ) ) {
		auto it = keyboards.get( event.get_id() );
		auto & keyboard = it.get_value();
		keyboard.pop();
	}
}

void Controller::handle( const PopAction< MouseAction > & event ) {

	// Get static references to global tables
	static auto & model = Model::instance();
	static auto & mice = model.get_table< MouseActionQueue >();

	// 
	if ( mice.has( event.get_id() ) ) {
		auto it = mice.get( event.get_id() );
		auto & mouse = it.get_value();
		mouse.pop();
	}
}
