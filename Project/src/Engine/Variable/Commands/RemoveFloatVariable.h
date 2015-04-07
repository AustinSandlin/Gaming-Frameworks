#ifndef _REMOVE_FLOAT_VARIABLE_H
#define _REMOVE_FLOAT_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../VariableController.h"

class RemoveFloatVariable :

	public Command {

private:

	String name;

public:

	RemoveFloatVariable( String name ) {
		this->name = name;
	}

	~RemoveFloatVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();

		// 
		variable_controller.removeFloatVariable( name );
	}
};

Command * parseRemoveFloatVariable( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveFloatVariable( name );
}

#endif
