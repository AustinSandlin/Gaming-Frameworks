#ifndef _AUDIO_CONTROLLER_H
#define _AUDIO_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Sound.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Types.h"

class AudioController:
	
	public Singleton< AudioController > {

	private:

		friend class Singleton< AudioController >;

		ALCdevice * device;
		ALCcontext * context;
		Table< Sound > sounds;

		AudioController();
		~AudioController();

	public:

		void addSound( String name, String path );
		void removeSound( String name );
		void playSound( String name, bool looping = false );
		void stopSound( String name );
		bool isPlayingSound( String name );
};

#endif
