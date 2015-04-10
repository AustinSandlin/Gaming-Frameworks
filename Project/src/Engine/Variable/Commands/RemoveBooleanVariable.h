#ifndef _REMOVE_BOOLEAN_VARIABLE_H
#define _REMOVE_BOOLEAN_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../VariableController.h"

class RemoveBooleanVariable :

	public Command {

private:

	String name;

public:

	RemoveBooleanVariable( String name ) {
		this->name = name;
	}

	~RemoveBooleanVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();

		// 
		variable_controller.removeBooleanVariable( name );
	}
};

Command * parseRemoveBooleanVariable( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveBooleanVariable( name );
}

#endif
