#ifndef _ADD_BOOLEAN_VARIABLE_H
#define _ADD_BOOLEAN_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../VariableController.h"

class AddBooleanVariable :

	public Command {

private:

	String name;

public:

	AddBooleanVariable( String name ) {
		this->name = name;
	}

	~AddBooleanVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();

		// 
		variable_controller.addBooleanVariable( name );
	}
};

Command * parseAddBooleanVariable( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new AddBooleanVariable( name );
}

#endif
