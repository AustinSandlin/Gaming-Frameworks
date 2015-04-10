#ifndef _ADD_SOUND_H
#define _ADD_SOUND_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../AudioController.h"

class AddSound :

	public Command {

private:

	String name;
	String path;

public:

	AddSound( String name, String path ) {
		this->name = name;
		this->path = path;
	}

	~AddSound() {
	}

	void run() {

		// 
		static AudioController & audio_controller = AudioController::instance(); 

		// 
		audio_controller.addSound( name, path );
	}
};

Command * parseAddSound( StringStream & tokens ) {

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
	return new AddSound( name, path );
}

#endif
