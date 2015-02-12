#include "Model.h"

using namespace Scheduler;

void handle( const Update & event ) {
	static auto & queue = get_queue< ScheduleEvent< Input::Controller, Object::AddProperty< Input::KeyboardActionQueue > > >();
	queue.push( event );
}


void handle( const ScheduleEvent< Input::Controller, Object::AddProperty< Input::KeyboardActionQueue > > & event ) {
	auto & queue = get_queue< ScheduleEvent< Input::Controller, Object::AddProperty< Input::KeyboardActionQueue > > >();
	queue.push( event );
}
