#ifndef _TRIGGER_COMMANDS_H
#define _TRIGGER_COMMANDS_H

#include "Commands/AddBooleanTrigger.h"
#include "Commands/RemoveBooleanTrigger.h"
#include "Commands/SetBooleanTrigger.h"

#include "Commands/AddIntegerTrigger.h"
#include "Commands/RemoveIntegerTrigger.h"
#include "Commands/SetIntegerTrigger.h"

#include "Commands/AddFloatTrigger.h"
#include "Commands/RemoveFloatTrigger.h"
#include "Commands/SetFloatTrigger.h"

#include "Commands/AddCollisionTrigger.h"
#include "Commands/RemoveCollisionTrigger.h"
#include "Commands/SetCollisionTrigger.h"

Command * parseTriggerCommand( StringStream & tokens ) {

	// 
	String type, command;

	// 
	tokens >> type;
	if ( type == "boolean" ) {

		// 
		tokens >> command;
		if ( command == "add" ) {
			return parseAddBooleanTrigger( tokens );
		}
		else if ( command == "remove" ) {
			return parseRemoveBooleanTrigger( tokens );
		}
		else if ( command == "set" ) {
			return parseSetBooleanTrigger( tokens );
		}
	}
	else if ( type == "integer" ) {

		// 
		tokens >> command;
		if ( command == "add" ) {
			return parseAddIntegerTrigger( tokens );
		}
		else if ( command == "remove" ) {
			return parseRemoveIntegerTrigger( tokens );
		}
		else if ( command == "set" ) {
			return parseSetIntegerTrigger( tokens );
		}
	}
	else if ( type == "float" ) {

		// 
		tokens >> command;
		if ( command == "add" ) {
			return parseAddFloatTrigger( tokens );
		}
		else if ( command == "remove" ) {
			return parseRemoveFloatTrigger( tokens );
		}
		else if ( command == "set" ) {
			return parseSetFloatTrigger( tokens );
		}
	}
	else if ( type == "collision" ) {

		// 
		tokens >> command;
		if ( command == "add" ) {
			return parseAddCollisionTrigger( tokens );
		}
		else if ( command == "remove" ) {
			return parseRemoveCollisionTrigger( tokens );
		}
		else if ( command == "set" ) {
			return parseSetCollisionTrigger( tokens );
		}
	}

	// 
	return NULL;
}

#endif
