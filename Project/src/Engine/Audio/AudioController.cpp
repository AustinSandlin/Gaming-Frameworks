#include "../../Common/Resources/Strings.h"

#include "AudioController.h"

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

	ALfloat position[] = { 0, 0, 0 };
	ALfloat velocity[] = { 0, 0, 0 };
	ALfloat orientation[] = { 0, 0, -1, 0, 0, 0 };

	alListenerfv( AL_POSITION, position );
	alListenerfv( AL_VELOCITY, velocity );
	alListenerfv( AL_ORIENTATION, orientation );
}

AudioController::~AudioController() {

	// ========================================================================
	// De-allocate resources
	// ========================================================================

	for ( auto it : sounds ) {
		Sound & sound = it.getValue();
		if ( sound.isLoaded() ) {
			sound.unload();
		}
	}
	alcDestroyContext( context );
	alcCloseDevice( device );
}

void AudioController::addSound( String name, String path ) {

	// ========================================================================
	// Get static table references
	// ========================================================================
	
	static Strings & strings = Strings::instance();

	// ========================================================================
	// Create a sound with the specified name
	// ========================================================================

	StringID id = strings.intern( name );
	if ( !sounds.has( id ) ) {
		sounds.add( id, Sound() );
	}

	// ========================================================================
	// Load the sound from the specified file
	// ========================================================================

	Sound & sound = sounds.get( id ).getValue();
	if ( sound.isLoaded() ) {
		sound.unload();
	}
	sound.load( path );
}

void AudioController::removeSound( String name ) {

	// ========================================================================
	// Get static table references
	// ========================================================================

	static Strings & strings = Strings::instance();

	// ========================================================================
	// Remove the sound with the specified name
	// ========================================================================

	StringID id = strings.intern( name );
	if ( sounds.has( id ) ) {
		Sound & sound = sounds.get( id ).getValue();
		if ( sound.isLoaded() ) {
			sound.unload();
		}
		sounds.remove( id );
	}
}

void AudioController::playSound( String name, bool looping ) {

	// ========================================================================
	// Get static table references
	// ========================================================================

	static Strings & strings = Strings::instance();

	// ========================================================================
	// Atttempt to play the sound
	// ========================================================================

	StringID id = strings.intern( name );
	if ( sounds.has( id ) ) {
		Sound & sound = sounds.get( id ).getValue();
		if ( sound.isPlaying() ) {
			sound.stop();
		}
		sound.play( looping );
	}
}

void AudioController::stopSound( String name ) {

	// ========================================================================
	// Get static table references
	// ========================================================================

	static Strings & strings = Strings::instance();

	// ========================================================================
	// Atttempt to stop playing the sound
	// ========================================================================

	StringID id = strings.intern( name );
	if ( sounds.has( id ) ) {
		Sound & sound = sounds.get( id ).getValue();
		if ( sound.isPlaying() ) {
			sound.stop();
		}
	}
}
