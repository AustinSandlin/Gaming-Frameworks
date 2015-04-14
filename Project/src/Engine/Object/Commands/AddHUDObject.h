#ifndef _ADD_HUD_OBJECT_H
#define _ADD_HUD_OBJECT_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../Objects/HUDObject.h"
#include "../ObjectController.h"

class AddHUDObject :

	public Command {

private:

	String name;
	String variable;
	int x;
	int y;
	int width;
	int height;
	bool debug;


public:

	AddHUDObject( String name, int x, int y, int width, int height, bool debug ) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->debug = debug;
	}

	~AddHUDObject() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static ObjectController & object_controller = ObjectController::instance(); 

		// 
		StringID id = strings.intern( name );
		object_controller.registerHUDObject( id, HUDObject( id, x, y, width, height, debug ) );
	}
};

Command * parseAddHUDObject( StringStream & tokens ) {

	// 
	String name, text;
	int x, y, height, width;
	bool debug;

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
	tokens >> text;
	if ( text == "true" ) {
		debug = true;
	}
	else if ( text == "false" ) {
		debug = false;
	}
	else {
		return NULL;
	}

	// 
	return new AddHUDObject( name, x, y, width, height, debug );
}

#endif
