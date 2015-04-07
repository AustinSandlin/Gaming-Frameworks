#ifndef _ADD_BOOLEAN_TRIGGER_H
#define _ADD_BOOLEAN_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../TriggerController.h"

class AddBooleanTrigger :

	public Command {

private:

	String name;
	String variable;
	String comparison;
	bool value;

public:

	AddBooleanTrigger( String name, String variable, String comparison, bool value ) {
		this->name = name;
		this->variable = variable;
		this->comparison = comparison;
		this->value = value;
	}

	~AddBooleanTrigger() {
	}

	void run() {

		// 
		static TriggerController & trigger_controller = TriggerController::instance();

		// 
		trigger_controller.addBooleanTrigger( name, variable, comparison, value );
	}
};

Command * parseAddBooleanTrigger( StringStream & tokens ) {

	// 
	String name, variable, comparison, text;
	bool value;

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
	if ( comparison != "==" && comparison != "!=" ) {
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
	return new AddBooleanTrigger( name, variable, comparison, value );
}

#endif
