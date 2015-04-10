#ifndef _SET_BOOLEAN_VARIABLE_H
#define _SET_BOOLEAN_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Trigger/TriggerController.h"

#include "../VariableController.h"

class SetBooleanVariable :

	public Command {

private:

	String name;
	bool value;

public:

	SetBooleanVariable( String name, bool value ) {
		this->name = name;
		this->value = value;
	}

	~SetBooleanVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();
		static TriggerController & trigger_controller = TriggerController::instance();

		if ( variable_controller.hasBooleanVariable( name ) ) {

			// 
			bool initial = variable_controller.getBooleanVariable( name );

			// 
			variable_controller.setBooleanVariable( name, value );

			// 
			if ( initial != variable_controller.getBooleanVariable( name ) ) {
				trigger_controller.updateBooleanTriggers( name );
			}
		}

	}
};

Command * parseSetBooleanVariable( StringStream & tokens ) {

	// 
	String name, text;
	bool value;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	tokens >> text;
	if ( text == "true" ) {
		value = true;
	}
	else if ( text == "false" ) {
		value = false;
	}
	else {
		return NULL;
	}

	// 
	return new SetBooleanVariable( name, value );
}

#endif
