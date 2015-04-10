#ifndef _ADD_GAME_OBJECT_H
#define _ADD_GAME_OBJECT_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../Objects/GameObject.h"
#include "../ObjectController.h"

class AddGameObject :

	public Command {

private:

	String name;
	int x;
	int y;
	int width;
	int height;
	bool collidable;


public:

	AddGameObject( String name, int x, int y, int width, int height, bool collidable ) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->collidable = collidable;
	}

	~AddGameObject() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static ObjectController & object_controller = ObjectController::instance(); 

		// 
		StringID id = strings.intern( name );
		object_controller.registerGameObject( id, GameObject( id, x, y, width, height, collidable ) );
	}
};

Command * parseAddGameObject( StringStream & tokens ) {

	// 
	String name, text;
	int x, y, height, width;
	bool collidable;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	tokens >> text;
	try {
		x = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	tokens >> text;
	try {
		y = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	tokens >> text;
	try {
		width = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	tokens >> text;
	try {
		height = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	tokens >> text;
	if ( text == "true" ) {
		collidable = true;
	}
	else if ( text == "false" ) {
		collidable = false;
	}
	else {
		return NULL;
	}

	// 
	return new AddGameObject( name, x, y, width, height, collidable );
}

#endif
