#include "../Input/Controller.h"
#include "../Scheduler/Controller.h"

#include "Model.h"

using namespace Object;

void Controller::handle( const RemoveObject & event ) {
	
	// Get static references to global tables
	static auto & input = Input::Controller::instance();
	static auto & scheduler = Scheduler::Controller::instance();

	// 
	input.handle( event );
	scheduler.handle( event );
}
