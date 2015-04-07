#ifndef _VARIABLE_COMMANDS_H
#define _VARIABLE_COMMANDS_H

#include "Commands/AddBooleanVariable.h"
#include "Commands/RemoveBooleanVariable.h"
#include "Commands/SetBooleanVariable.h"

#include "Commands/AddIntegerVariable.h"
#include "Commands/RemoveIntegerVariable.h"
#include "Commands/SetIntegerVariable.h"

#include "Commands/AddFloatVariable.h"
#include "Commands/RemoveFloatVariable.h"
#include "Commands/SetFloatVariable.h"

Command * parseVariableCommand( StringStream & tokens ) {

	// 
	String type, command;

	// 
	tokens >> type;
	if ( type == "boolean" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddBooleanVariable( tokens );
		}
		else if ( command == "remove" ) {
			return parseRemoveBooleanVariable( tokens );
		}
		else if ( command == "set" ) {
			return parseSetBooleanVariable( tokens );
		}
	}

	// 
	else if ( type == "integer" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddIntegerVariable( tokens );
		}
		else if ( command == "remove" ) {
			return parseRemoveIntegerVariable( tokens );
		}
		else if ( command == "set" ) {
			return parseSetIntegerVariable( tokens );
		}
	}

	// 
	else if ( type == "float" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddFloatVariable( tokens );
		}
		else if ( command == "remove" ) {
			return parseRemoveFloatVariable( tokens );
		}
		else if ( command == "set" ) {
			return parseSetFloatVariable( tokens );
		}
	}

	// 
	return NULL;
}

#endif
