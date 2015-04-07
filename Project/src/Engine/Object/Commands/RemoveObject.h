#ifndef _REMOVE_OBJECT_H
#define _REMOVE_OBJECT_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../ObjectController.h"

class RemoveObject :

	public Command {

private:

	String name;

public:

	RemoveObject( String name ) {
		this->name = name;
	}

	~RemoveObject() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static ObjectController & object_controller = ObjectController::instance(); 

		// 
		StringID id = strings.intern( name );
		object_controller.removeObject( id );
	}
};

Command * parseRemoveObject( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveObject( name );
}

#endif
