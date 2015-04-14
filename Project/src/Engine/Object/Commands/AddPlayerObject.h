#ifndef _ADD_PLAYER_OBJECT_H
#define _ADD_PLAYER_OBJECT_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../Objects/PlayerObject.h"
#include "../ObjectController.h"

class AddPlayerObject :

	public Command {

private:

	String name;
	int x;
	int y;
	int width;
	int height;


public:

	AddPlayerObject( String name, int x, int y, int width, int height ) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	~AddPlayerObject() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static ObjectController & object_controller = ObjectController::instance(); 

		// 
		StringID id = strings.intern( name );
		object_controller.registerPlayerObject( id, PlayerObject( id, x, y, width, height ) );
	}
};

Command * parseAddPlayerObject( StringStream & tokens ) {

	// 
	String name, text;
	int x, y, height, width;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	//tokens >> text;
	try {
		tokens >> x;
		//x = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	//tokens >> text;
	try {
		tokens >> y;
		//y = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	//tokens >> text;
	try {
		tokens >> width;
		//width = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	//tokens >> text;
	try {
		tokens >> height;
		//height = stoi( text );
	}
	catch ( exception e ) {
		return NULL;
	}

	// 
	return new AddPlayerObject( name, x, y, width, height );
}

#endif
