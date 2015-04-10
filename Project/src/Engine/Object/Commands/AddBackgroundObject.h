#ifndef _ADD_BACKGROUND_OBJECT_H
#define _ADD_BACKGROUND_OBJECT_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../Objects/BackgroundObject.h"
#include "../ObjectController.h"

class AddBackgroundObject :

	public Command {

private:

	String name;
	int x;
	int y;
	int width;
	int height;


public:

	AddBackgroundObject( String name, int x, int y, int width, int height ) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	~AddBackgroundObject() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static ObjectController & object_controller = ObjectController::instance(); 

		// 
		StringID id = strings.intern( name );
		object_controller.registerBackgroundObject( id, BackgroundObject( id, x, y, width, height ) );
	}
};

Command * parseAddBackgroundObject( StringStream & tokens ) {

	// 
	String name, text;
	int x, y, height, width;

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
	return new AddBackgroundObject( name, x, y, width, height );
}

#endif
