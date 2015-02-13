#include "../Input/InputController.h"
#include "../Scheduler/SchedulerController.h"

#include "ObjectModel.h"

using namespace Object;

void Controller::handle( const RemoveObject & event ) {
	
	static auto & scheduler = Scheduler::SchedulerController::instance();

	// 
	input.handle( event );
	scheduler.handle( event );
}
