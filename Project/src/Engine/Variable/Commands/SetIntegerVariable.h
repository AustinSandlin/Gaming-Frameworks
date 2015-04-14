#ifndef _SET_INTEGER_VARIABLE_H
#define _SET_INTEGER_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Trigger/TriggerController.h"

#include "../VariableController.h"

class SetIntegerVariable :

	public Command {

private:

	String name;
	String operation;
	long value;

public:

	SetIntegerVariable( String name, String operation, long value ) {
		this->name = name;
		this->operation = operation;
		this->value = value;
	}

	~SetIntegerVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		if ( variable_controller.hasIntegerVariable( name ) ) {

			// 
			long initial = variable_controller.getIntegerVariable( name );

			// 
			if ( operation == "=" ) {
				variable_controller.setIntegerVariable( name, value );
			}
			else if ( operation == "+=" ) {
				variable_controller.setIntegerVariable( name, initial + value );
			}
			else if ( operation == "-=" ) {
				variable_controller.setIntegerVariable( name, initial - value );
			}
			else if ( operation == "*=" ) {
				variable_controller.setIntegerVariable( name, initial * value );
			}
			else if ( operation == "/=" ) {
				variable_controller.setIntegerVariable( name, initial / value );
			}

			// 
			if ( initial != variable_controller.getIntegerVariable( name ) ) {

				trigger_controller.updateIntegerTriggers( name );
			}
		}
	}
};

Command * parseSetIntegerVariable( StringStream & tokens ) {

	// 
	String name, operation, text;
	long value;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	tokens >> operation;
	if ( operation != "=" && operation != "+=" && operation != "-=" && operation != "*=" && operation != "/=" ) {
		return NULL;
	}

	// 
	//tokens >> text;
	try {
		tokens >> value;
		//value = stol( text );
	}
	catch ( exception e ) {
		return NULL;
	}
	if ( operation == "/=" && value == 0 ) {
		return NULL;
	}
	
	// 
	return new SetIntegerVariable( name, operation, value );
}

#endif
