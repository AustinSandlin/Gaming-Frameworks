#ifndef _STOP_SOUND_H
#define _STOP_SOUND_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../AudioController.h"

class StopSound :

	public Command {

private:

	String name;

public:

	StopSound( String name ) {
		this->name = name;
	}

	~StopSound() {
	}

	void run() {

		// 
		static AudioController & audio_controller = AudioController::instance(); 

		// 
		audio_controller.stopSound( name );
	}
};

Command * parseStopSound( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}
	
	// 
	return new StopSound( name );
}

#endif
