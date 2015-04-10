#ifndef _ADD_FLOAT_VARIABLE_H
#define _ADD_FLOAT_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../VariableController.h"

class AddFloatVariable :

	public Command {

private:

	String name;

public:

	AddFloatVariable( String name ) {
		this->name = name;
	}

	~AddFloatVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();

		// 
		variable_controller.addFloatVariable( name );
	}
};

Command * parseAddFloatVariable( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	return new AddFloatVariable( name );
}

#endif
