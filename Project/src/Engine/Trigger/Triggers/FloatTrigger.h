#ifndef _FLOAT_TRIGGER_H
#define _FLOAT_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Variable/VariableController.h"

#include <list>

class FloatTrigger {

private:

	String variable;
	String comparison;
	double value;
	std::list< Command * > commands;

public:

	FloatTrigger( String variable, String comparison, double value ) {
		this->variable = variable;
		this->comparison = comparison;
		this->value = value;
	}

	~FloatTrigger() {

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
		if ( variable_controller.hasFloatVariable( variable ) ) {

			// 
			if ( comparison == "==" ) {
				return variable_controller.getFloatVariable( variable ) == value;
			}
			else if ( comparison == "!=" ) {
				return variable_controller.getFloatVariable( variable ) != value;
			}
			else if ( comparison == "<=" ) {
				return variable_controller.getFloatVariable( variable ) <= value;
			}
			else if ( comparison == ">=" ) {
				return variable_controller.getFloatVariable( variable ) >= value;
			}
			else if ( comparison == "<" ) {
				return variable_controller.getFloatVariable( variable ) < value;
			}
			else if ( comparison == ">" ) {
				return variable_controller.getFloatVariable( variable ) > value;
			}
		}

		// 
		return false;
	}
};

#endif
