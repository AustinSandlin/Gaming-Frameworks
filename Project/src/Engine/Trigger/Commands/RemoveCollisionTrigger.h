#ifndef _REMOVE_COLLISION_TRIGGER_H
#define _REMOVE_COLLISION_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class RemoveCollisionTrigger :

	public Command {

private:

	String name;

public:

	RemoveCollisionTrigger( String name ) {
		this->name = name;
	}

	~RemoveCollisionTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.removeCollisionTrigger( name );
	}
};

Command * parseRemoveCollisionTrigger( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveCollisionTrigger( name );
}

#endif
