#ifndef _AUDIO_CONTROLLER_H
#define _AUDIO_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Types.h"

#include "Sound.h"

class AudioController:
	
	public Singleton< AudioController > {

	private:

		friend class Singleton< AudioController >;

		ALCdevice * device;
		ALCcontext * context;
		ALuint source;
		Table< ALuint > buffers;

		AudioController();
		~AudioController();

	public:

		void playSound( String path );
};

#endif
