#ifndef _SOUND_H
#define _SOUND_H

#if __APPLE__ 
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif

#include <cstdlib>



#include <iostream>
using namespace std;



class Sound {

private:

	bool loaded;
	ALuint source;
	ALuint buffer;

public:
	
	void load( String path ) {

        char chunk_id[5] = { '\0' };
        int chunk_size;

        // ====================================================================
        // Open the file
        // ====================================================================

        FILE * file = fopen( path.data(), "rb" );
        if ( file == NULL ) {
            throw "File Not Found";
        }
        
        // ====================================================================
        // Read the RIFF chunk
        // ====================================================================

        if ( fread( chunk_id, sizeof(char), 4, file ) != 4 ||
        	strcmp( chunk_id, "RIFF" ) != 0 ) {
            throw "Invalid Chunk ID: RIFF";
        }

        fread( & chunk_size, sizeof(int), 1, file );

        if ( fread( chunk_id, sizeof(char), 4, file ) != 4 ||
        	strcmp( chunk_id, "WAVE" ) != 0 ) {
            throw "Invalid Format";
        }

        // ====================================================================
        // Read the format chunk
        // ====================================================================

        short audio_format;
        short channels;
        int sample_rate;
        int byte_rate;
        short block_align;
        short bits_per_sample;
        short extra_param_size;
        unsigned char * extra_params;

        if ( fread( chunk_id, sizeof(char), 4, file ) != 4 ||
        	strcmp( chunk_id, "fmt " ) != 0 ) {
            throw "Invalid Chunk ID: Format";
        }

        fread( & chunk_size, sizeof(int), 1, file );
        fread( & audio_format, sizeof(short), 1, file );
        fread( & channels, sizeof(short), 1, file );
        fread( & sample_rate, sizeof(int), 1, file );
        fread( & byte_rate, sizeof(int), 1, file );
        fread( & block_align, sizeof(short), 1, file );
        fread( & bits_per_sample, sizeof(short), 1, file );

        if ( chunk_size > 16 ) { // Ignore any extra parameters
            fread( & extra_param_size, sizeof(short), 1, file );
            extra_params = new unsigned char[ extra_param_size ];
            fread( extra_params, sizeof(char), extra_param_size, file );
            delete[] extra_params;
        }

        // ====================================================================
        // Read the data chunk
        // ====================================================================

        unsigned char * data;

        if ( fread( chunk_id, sizeof(char), 4, file ) != 4 ||
        	strcmp( chunk_id, "data" ) != 0 ) {
            throw "Invalid Chunk ID: Data";
        }

        fread( & chunk_size, sizeof(int), 1, file );
        data = new unsigned char[ chunk_size ];
        fread( data, sizeof(char), chunk_size, file );

        // ====================================================================
        // Close the file
        // ====================================================================

        fclose( file );

        // ====================================================================
        // Determine the sound's format
        // ====================================================================

        ALenum format;
        if ( channels  == 1 ) {
            if ( bits_per_sample == 8 ) {
                format = AL_FORMAT_MONO8;
            }
            else {
                format = AL_FORMAT_MONO16;
            }
        }
        else {
            if ( bits_per_sample == 8 ) {
                format = AL_FORMAT_STEREO8;
            }
            else {
                format = AL_FORMAT_STEREO16;
            }
        }

        // ====================================================================
        // Load the sound into the buffer
        // ====================================================================

        alGenBuffers( 1, & buffer );
        alBufferData( buffer, format, data, chunk_size, sample_rate );
        delete[] data;

        // ========================================================================
		// Create the source
		// ========================================================================

        ALfloat position[] = { 0, 0, 0 };
        ALfloat velocity[] = { 0, 0, 0 };

		alGenSources( 1, & source );
		alSourcef( source, AL_PITCH, 1 );
		alSourcef( source, AL_GAIN, 1 );
		alSourcefv( source, AL_POSITION, position );
		alSourcefv( source, AL_VELOCITY, velocity );
        alSourcei( source, AL_BUFFER, buffer );

        // ====================================================================
		// Set the loaded flag
		// ====================================================================

		loaded = true;
	}
	void unload() {

        // ====================================================================
		// De-allocate resources for this sound
		// ====================================================================

		alDeleteSources( 1, & source );
		alDeleteBuffers( 1, & buffer );

        // ====================================================================
		// Clear the loaded flag
		// ====================================================================

		loaded = false;
	}
	void play( bool looping ) {

		// ====================================================================
		// Play the sound
		// ====================================================================

		if ( looping ) {
			alSourcei( source, AL_LOOPING, AL_TRUE );
		}
		else {
			alSourcei( source, AL_LOOPING, AL_FALSE );
		}
		alSourcePlay( source );
	}
	void stop() {

		// ====================================================================
		// Stop playing the sound
		// ====================================================================

		alSourceStop( source );
	}
	bool isLoaded() {
		return loaded;
	}
	bool isPlaying() {
		if ( isLoaded() ) {
			ALenum state;
			alGetSourcei( source, AL_SOURCE_STATE, & state );
			return state == AL_PLAYING;
		}
		else {
			return false;
		}
	}
};

#endif
