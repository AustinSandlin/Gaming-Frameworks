#ifndef _OBJECT_COMMANDS_H
#define _OBJECT_COMMANDS_H

#include "Commands/AddAIObject.h"
#include "Commands/AddBackgroundObject.h"
#include "Commands/AddGameObject.h"
#include "Commands/AddHUDObject.h"
#include "Commands/BindHudObject.h"
#include "Commands/AddPlayerObject.h"
#include "Commands/SetTexture.h"

Command * parseObjectCommand( StringStream & tokens ) {

	// 
	String type, command;

	// 
	tokens >> type;
	if ( type == "ai" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddAIObject( tokens );
		}
	}
	else if ( type == "background" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddBackgroundObject( tokens );
		}
	}
	else if ( type == "game" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddGameObject( tokens );
		}
	}
	else if ( type == "hud" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddHUDObject( tokens );
		}
		if ( command == "bind" ) {
			return parseBindHUDObject( tokens );
		}
	}
	else if ( type == "player" ) {

		// 
		tokens >> command;
		if ( command == "add") {
			return parseAddPlayerObject( tokens );
		}
	}
	else if ( type == "texture" ) {

		// 
		tokens >> command;
		if ( command == "set") {
			return parseSetTexture( tokens );
		}
	}

	// 
	return NULL;
}

#endif
