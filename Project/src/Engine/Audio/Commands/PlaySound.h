#ifndef _PLAY_SOUND_H
#define _PLAY_SOUND_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../AudioController.h"

class PlaySound :

	public Command {

private:

	String name;

public:

	PlaySound( String name ) {
		this->name = name;
	}

	~PlaySound() {
	}

	void run() {

		// 
		static AudioController & audio_controller = AudioController::instance(); 

		// 
		audio_controller.playSound( name );
	}
};

Command * parsePlaySound( StringStream & tokens ) {

	// 
	String name;

	// 
	tokens >> name;
	if ( name.empty() ) {
		return NULL;
	}
	
	// 
	return new PlaySound( name );
}

#endif
