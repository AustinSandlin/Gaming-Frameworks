#ifndef _INPUT_COMMANDS_H
#define _INPUT_COMMANDS_H

#include "Commands/BindKey.h"

Command * parseInputCommand( StringStream & tokens ) {

	// 
	String command;

	// 
	tokens >> command;
	if ( command == "bind" ) {
		return parseBindKey( tokens );
	}

	// 
	return NULL;
}

#endif
