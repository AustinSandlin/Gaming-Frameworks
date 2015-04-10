#ifndef _REMOVE_SOUND_H
#define _REMOVE_SOUND_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../AudioController.h"

class RemoveSound :

	public Command {

private:

	String name;

public:

	RemoveSound( String name ) {
		this->name = name;
	}

	~RemoveSound() {
	}

	void run() {

		// 
		static AudioController & audio_controller = AudioController::instance(); 

		// 
		audio_controller.removeSound( name );
	}
};

Command * parseRemoveSound( StringStream & tokens ) {

	// 
	String name;
	tokens >> name;

	// 
	if ( name.empty() ) {
		return NULL;
	}
	
	// 
	return new RemoveSound( name );
}

#endif
