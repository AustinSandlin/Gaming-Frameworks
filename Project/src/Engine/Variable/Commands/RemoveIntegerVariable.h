#ifndef _REMOVE_INTEGER_VARIABLE_H
#define _REMOVE_INTEGER_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../VariableController.h"

class RemoveIntegerVariable :

	public Command {

private:

	String name;

public:

	RemoveIntegerVariable( String name ) {
		this->name = name;
	}

	~RemoveIntegerVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();

		// 
		variable_controller.removeIntegerVariable( name );
	}
};

Command * parseRemoveIntegerVariable( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new RemoveIntegerVariable( name );
}

#endif
