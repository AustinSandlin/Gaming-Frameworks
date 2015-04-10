#ifndef _SET_FLOAT_VARIABLE_H
#define _SET_FLOAT_VARIABLE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Trigger/TriggerController.h"

#include "../VariableController.h"

class SetFloatVariable :

	public Command {

private:

	String name;
	String operation;
	double value;

public:

	SetFloatVariable( String name, String operation, double value ) {
		this->name = name;
		this->operation = operation;
		this->value = value;
	}

	~SetFloatVariable() {
	}

	void run() {

		// 
		static VariableController & variable_controller = VariableController::instance();
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		if ( variable_controller.hasFloatVariable( name ) ) {

			// 
			double initial = variable_controller.getFloatVariable( name );

			// 
			if ( operation == "=" ) {
				variable_controller.setFloatVariable( name, value );
			}
			else if ( operation == "+=" ) {
				variable_controller.setFloatVariable( name, initial + value );
			}
			else if ( operation == "-=" ) {
				variable_controller.setFloatVariable( name, initial - value );
			}
			else if ( operation == "*=" ) {
				variable_controller.setFloatVariable( name, initial * value );
			}
			else if ( operation == "/=" ) {
				variable_controller.setFloatVariable( name, initial / value );
			}

			// 
			if ( initial != variable_controller.getFloatVariable( name ) ) {
				trigger_controller.updateFloatTriggers( name );
			}
		}
	}
};

Command * parseSetFloatVariable( StringStream & tokens ) {

	// 
	String name, operation, text;
	double value;

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
	tokens >> text;
	try {
		value = stod( text );
	}
	catch ( exception e ) {
		return NULL;
	}
	if ( operation == "/=" && value == 0.0 ) {
		return NULL;
	}
	
	// 
	return new SetFloatVariable( name, operation, value );
}

#endif
