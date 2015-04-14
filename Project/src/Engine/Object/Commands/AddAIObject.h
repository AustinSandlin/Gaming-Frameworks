#ifndef _ADD_AI_OBJECT_H
#define _ADD_AI_OBJECT_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../Objects/AIObject.h"
#include "../ObjectController.h"

class AddAIObject :

	public Command {

private:

	String name;
	int x;
	int y;
	int width;
	int height;
	AIType type;


public:

	AddAIObject( String name, int x, int y, int width, int height, AIType type ) {
		this->name = name;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->type = type;
	}

	~AddAIObject() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static ObjectController & object_controller = ObjectController::instance(); 

		// 
		StringID id = strings.intern( name );
		object_controller.registerAIObject( id, AIObject( id, x, y, width, height, type ) );
	}
};

Command * parseAddAIObject( StringStream & tokens ) {

	// 
	String name, text;
	int x, y, height, width;
	AIType type;

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
	if ( text == "rusher" ) {
		type = RUSHER;
	}
	else if ( text == "wander" ) {
		type = WANDER;
	}
	else if ( text == "still" ) {
		type = STILL;
	}
	else {
		return NULL;
	}

	// 
	return new AddAIObject( name, x, y, width, height, type );
}

#endif
