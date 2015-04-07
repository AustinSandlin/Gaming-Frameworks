#ifndef _REMOVE_BOOLEAN_TRIGGER_H
#define _REMOVE_BOOLEAN_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class RemoveBooleanTrigger :

	public Command {

private:

	String name;

public:

	RemoveBooleanTrigger( String name ) {
		this->name = name;
	}

	~RemoveBooleanTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.removeBooleanTrigger( name );
	}
};

Command * parseRemoveBooleanTrigger( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveBooleanTrigger( name );
}

#endif
