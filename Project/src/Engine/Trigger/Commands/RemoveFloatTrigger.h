#ifndef _REMOVE_FLOAT_TRIGGER_H
#define _REMOVE_FLOAT_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class RemoveFloatTrigger :

	public Command {

private:

	String name;

public:

	RemoveFloatTrigger( String name ) {
		this->name = name;
	}

	~RemoveFloatTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.removeFloatTrigger( name );
	}
};

Command * parseRemoveFloatTrigger( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveFloatTrigger( name );
}

#endif
