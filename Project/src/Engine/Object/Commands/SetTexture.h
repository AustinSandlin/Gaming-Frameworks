#ifndef _SET_TEXTURE_H
#define _SET_TEXTURE_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../Objects/AIObject.h"
#include "../ObjectController.h"

class SetTexture :

	public Command {

private:

	String name;
	String path;

public:

	SetTexture( String name, String path ) {
		this->name = name;
		this->path = path;
	}

	~SetTexture() {
	}

	void run() {

		// 
		static Strings & strings = Strings::instance();
		static ObjectController & object_controller = ObjectController::instance(); 

		// 
		StringID id = strings.intern( name );
		object_controller.registerObjectTexture( id, path );
	}
};

Command * parseSetTexture( StringStream & tokens ) {

	// 
	String name, path;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}

	// 
	tokens >> path;
	if ( path.empty() ) {
		return NULL;
	}

	// 
	return new SetTexture( name, path );
}

#endif
