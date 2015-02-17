#include "../../Common/Resources/Strings.h"

#include "AudioController.h"
#include "Sound.h"

AudioController::AudioController() {

	// ========================================================================
	// Create a context
	// ========================================================================

	device = alcOpenDevice( NULL );
	context = alcCreateContext( device, NULL );
	alcMakeContextCurrent( context );

	// ========================================================================
	// Define the listener
	// ========================================================================

	alListener3f(AL_POSITION, 0, 0, 0);
	alListener3f(AL_VELOCITY, 0, 0, 0);
	alListener3f(AL_ORIENTATION, 0, 0, -1);

	// ========================================================================
	// Create the source (only one for now)
	// ========================================================================

	alGenSources( 1, &source );
	alSourcef( source, AL_PITCH, 1 );
	alSourcef( source, AL_GAIN, 1 );
	alSource3f( source, AL_POSITION, 0, 0, 0 );
	alSource3f( source, AL_VELOCITY, 0, 0, 0 );
	alSourcei( source, AL_LOOPING, AL_FALSE );
}

AudioController::~AudioController() {

	// ========================================================================
	// Clean up
	// ========================================================================

	alDeleteSources( 1, &source );
	for ( auto buffer : buffers ) {
		alDeleteBuffers( 1, &(buffer.getValue()) );
	}
	alcDestroyContext( context );
	alcCloseDevice( device );
}

void AudioController::playSound( String path ) {

	// ========================================================================
	// Get static table references
	// ========================================================================

	static Strings& strings = Strings::instance();

	// ========================================================================
	// Create a buffer for the sound if one doesn't exist
	// ========================================================================

	StringID id = strings.intern( path );
	if ( !buffers.has( id ) ) {
		Sound sound( path );
		buffers.add( id, sound.toBuffer() );
	}

	// ========================================================================
	// Stop the sound if it's already playing
	// ========================================================================

	ALenum state;
	alGetSourcei( source, AL_SOURCE_STATE, &state );
	if ( state == AL_PLAYING) {
		alSourceStop( source );
	}

	// ========================================================================
	// Play the sound
	// ========================================================================

	ALuint buffer = buffers.get( id ).getValue();
	alSourcei( source, AL_BUFFER, buffer );
	alSourcePlay( source );
}
