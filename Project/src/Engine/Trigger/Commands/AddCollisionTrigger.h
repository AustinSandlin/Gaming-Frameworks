#ifndef _ADD_COLLISION_TRIGGER_H
#define _ADD_COLLISION_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class AddCollisionTrigger :

	public Command {

private:

	String name;
	String first;
	String second;

public:

	AddCollisionTrigger( String name, String first, String second ) {
		this->name = name;
		this->first = first;
		this->second = second;
	}

	~AddCollisionTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.addCollisionTrigger( name, first, second );
	}
};

Command * parseAddCollisionTrigger( StringStream & tokens ) {

	// 
	String name, first, second;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	tokens >> first;
	if ( first.empty() ) {
		return NULL;
	}

	tokens >> second;
	if ( second.empty() ) {
		return NULL;
	}

	// 
	return new AddCollisionTrigger( name, first, second );
}

#endif
