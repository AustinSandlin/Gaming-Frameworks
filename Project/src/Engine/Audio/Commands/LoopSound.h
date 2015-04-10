#ifndef _LOOP_SOUND_H
#define _LOOP_SOUND_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../AudioController.h"

class LoopSound :

	public Command {

private:

	String name;

public:

	LoopSound( String name ) {
		this->name = name;
	}

	~LoopSound() {
	}

	void run() {

		// 
		static AudioController & audio_controller = AudioController::instance(); 

		// 
		audio_controller.playSound( name, true );
	}
};

Command * parseLoopSound( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}
	
	// 
	return new LoopSound( name );
}

#endif
