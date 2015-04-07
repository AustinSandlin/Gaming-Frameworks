#ifndef _REMOVE_INTEGER_TRIGGER_H
#define _REMOVE_INTEGER_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class RemoveIntegerTrigger :

	public Command {

private:

	String name;

public:

	RemoveIntegerTrigger( String name ) {
		this->name = name;
	}

	~RemoveIntegerTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.removeIntegerTrigger( name );
	}
};

Command * parseRemoveIntegerTrigger( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveIntegerTrigger( name );
}

#endif
