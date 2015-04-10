#ifndef _ADD_INTEGER_VARIABLE_H
#define _ADD_INTEGER_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../VariableController.h"

class AddIntegerVariable :

	public Command {

private:

	String name;

public:

	AddIntegerVariable( String name ) {
		this->name = name;
	}

	~AddIntegerVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();

		// 
		variable_controller.addIntegerVariable( name );
	}
};

Command * parseAddIntegerVariable( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new AddIntegerVariable( name );
}

#endif
