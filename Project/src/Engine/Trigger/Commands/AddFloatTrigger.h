#ifndef _ADD_FLOAT_TRIGGER_H
#define _ADD_FLOAT_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class AddFloatTrigger :

	public Command {

private:

	String name;
	String variable;
	String comparison;
	double value;

public:

	AddFloatTrigger( String name, String variable, String comparison, double value ) {
		this->name = name;
		this->variable = variable;
		this->comparison = comparison;
		this->value = value;
	}

	~AddFloatTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.addFloatTrigger( name, variable, comparison, value );
	}
};

Command * parseAddFloatTrigger( StringStream & tokens ) {

	// 
	String name, variable, comparison, text;
	double value;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	tokens >> variable;
	if ( variable.empty() ) {
		return NULL;
	}

	// 
	tokens >> comparison;
	if ( comparison != "==" && comparison != "!=" && comparison != "<=" && comparison != ">=" && comparison != "<" && comparison != ">" ) {
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

	// 
	return new AddFloatTrigger( name, variable, comparison, value );
}

#endif
