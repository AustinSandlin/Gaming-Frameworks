#ifndef _ADD_INTEGER_TRIGGER_H
#define _ADD_INTEGER_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class AddIntegerTrigger :

	public Command {

private:

	String name;
	String variable;
	String comparison;
	long value;

public:

	AddIntegerTrigger( String name, String variable, String comparison, long value ) {
		this->name = name;
		this->variable = variable;
		this->comparison = comparison;
		this->value = value;
	}

	~AddIntegerTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.addIntegerTrigger( name, variable, comparison, value );
	}
};

Command * parseAddIntegerTrigger( StringStream & tokens ) {

	// 
	String name, variable, comparison, text;
	long value;

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
		value = stol( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	return new AddIntegerTrigger( name, variable, comparison, value );
}

#endif
