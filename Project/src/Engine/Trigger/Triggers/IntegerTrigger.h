#ifndef _BOOLEAN_TRIGGER_H
#define _BOOLEAN_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Variable/VariableController.h"

#include <list>

class IntegerTrigger {

private:

	String variable;
	String comparison;
	long value;
	std::list< Command * > commands;

public:

	IntegerTrigger( String variable, String comparison, long value ) {
		this->variable = variable;
		this->comparison = comparison;
		this->value = value;
	}

	~IntegerTrigger() {

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
		if ( variable_controller.hasIntegerVariable( variable ) ) {

			// 
			if ( comparison == "==" ) {
				return variable_controller.getIntegerVariable( variable ) == value;
			}
			else if ( comparison == "!=" ) {
				return variable_controller.getIntegerVariable( variable ) != value;
			}
			else if ( comparison == "<=" ) {
				return variable_controller.getIntegerVariable( variable ) <= value;
			}
			else if ( comparison == ">=" ) {
				return variable_controller.getIntegerVariable( variable ) >= value;
			}
			else if ( comparison == "<" ) {
				return variable_controller.getIntegerVariable( variable ) > value;
			}
			else if ( comparison == ">" ) {
				return variable_controller.getIntegerVariable( variable ) > value;
			}
		}

		// 
		return false;
	}
};

#endif
