#ifndef _SOUND_H
#define _SOUND_H

#include "../../Common/Base/Types.h"

#include <cstdlib>
#include <cstdio>
#include <cstring>

#if __APPLE__ 
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif

#include <iostream>
using namespace std;

class Sound {

private:

    // ========================================================================
    // Format
    // ========================================================================

    short audio_format;
    short channels;
    int sample_rate;
    int byte_rate;
    short block_align;
    short bits_per_sample;

    // ========================================================================
    // Data
    // ========================================================================

    int size;
    unsigned char* data;

public:

    Sound( String path ) {

        char chunkID[5] = { '\0' };
        int chunkSize;

        // ====================================================================
        // Open the file
        // ====================================================================

        FILE * fp = fopen( path.data(), "rb" );
        if ( fp == NULL ) {
            cerr << "File Not Found" << endl;
            throw "File Not Found";
        }
        
        // ====================================================================
        // Read the RIFF chunk
        // ====================================================================

        if (fread( chunkID, sizeof(char), 4, fp ) != 4 || strcmp( chunkID, "RIFF" ) != 0 ) {
            throw "Invalid Chunk ID : RIFF";
        }

        fread( &chunkSize, sizeof(int), 1, fp );
        if ( fread( chunkID, sizeof(char), 4, fp ) != 4 || strcmp( chunkID, "WAVE" ) != 0 ) {
            throw "Invalid Format";
        }

        // ====================================================================
        // Read the format chunk
        // ====================================================================

        if ( fread( chunkID, sizeof(char), 4, fp ) != 4 || strcmp( chunkID, "fmt " ) != 0 ) {
            throw "Invalid Chunk ID : Format";
        }

        fread( &chunkSize, sizeof(int), 1, fp );
        fread( &audio_format, sizeof(short), 1, fp );
        fread( &channels, sizeof(short), 1, fp );
        fread( &sample_rate, sizeof(int), 1, fp );
        fread( &byte_rate, sizeof(int), 1, fp );
        fread( &block_align, sizeof(short), 1, fp );
        fread( &bits_per_sample, sizeof(short), 1, fp );
        
        if ( chunkSize > 16 ) { // Ignore any extra parameters
            short extraParamSize;
            fread( &extraParamSize, sizeof(short), 1, fp );
            unsigned char * extraParams = new unsigned char[extraParamSize];
            fread( extraParams, sizeof(char), extraParamSize, fp );
            delete[] extraParams;
        }

        // ====================================================================
        // Read the data chunk
        // ====================================================================

        if ( fread( chunkID, sizeof(char), 4, fp ) != 4 || strcmp( chunkID, "data" ) != 0 ) {
            throw "Invalid Chunk ID : Data";
        }

        fread( &size, sizeof(int), 1, fp );
        data = new unsigned char[ size ];
        fread( data, sizeof(char), size, fp );

        // ====================================================================
        // Close the file
        // ====================================================================

        fclose(fp);
    }
    ~Sound() {
        delete[] data;
    }
    ALuint toBuffer() {

        // ====================================================================
        // Determine the sound's format
        // ====================================================================

        ALuint buffer;
        alGenBuffers( 1, &buffer );

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

        alBufferData( buffer, format, data, size, sample_rate );
        return buffer;
    }
};

#endif
