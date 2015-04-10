#ifndef _INTEGER_TRIGGER_H
#define _INTEGER_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Variable/VariableController.h"

#include <list>

class BooleanTrigger {

private:

	String variable;
	String comparison;
	bool value;
	std::list< Command * > commands;

public:

	BooleanTrigger( String variable, String comparison, bool value ) {
		this->variable = variable;
		this->comparison = comparison;
		this->value = value;
	}

	~BooleanTrigger() {

		// 
		for ( Command * command : commands ) {
			delete command;
		}
	}

	void addCommand( Command * command ) {

		// 
		if ( command != NULL ) {
			commands.push_back( command );
		}
	}

	void runCommands() {

		// 
		for ( Command * command : commands ) {
			command->run();
		}
	}

	bool hasVariable( String variable ) {
		return this->variable == variable;
	}

	bool hasFired() {

		// 
		static VariableController & variable_controller = VariableController::instance();

		// 
		if ( variable_controller.hasBooleanVariable( variable ) ) {

			// 
			if ( comparison == "==" ) {
				return variable_controller.getBooleanVariable( variable ) == value;
			}
			else if ( comparison == "!=" ) {
				return variable_controller.getBooleanVariable( variable ) != value;
			}
		}

		// 
		return false;
	}
};

#endif
