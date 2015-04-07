#ifndef _AUDIO_COMMANDS_H
#define _AUDIO_COMMANDS_H

#include "Commands/AddSound.h"
#include "Commands/RemoveSound.h"
#include "Commands/PlaySound.h"
#include "Commands/LoopSound.h"
#include "Commands/StopSound.h"

Command * parseAudioCommand( StringStream & tokens ) {

	// 
	String command;

	// 
	tokens >> command;
	if ( command == "add") {
		return parseAddSound( tokens );
	}
	else if ( command == "remove" ) {
		return parseRemoveSound( tokens );
	}
	else if ( command == "play" ) {
		return parsePlaySound( tokens );
	}
	else if ( command == "loop" ) {
		return parseLoopSound( tokens );
	}
	else if ( command == "stop" ) {
		return parseStopSound( tokens );
	}

	// 
	return NULL;
}

#endif
