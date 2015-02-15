#ifndef _TYPES_H
#define _TYPES_H

#include <string>
#include <chrono>

//A few string things. StringID is unique identifier based on a string hash.
typedef int StringID;
//Easier use of string without calling std:: everywhere.
typedef std::string String;

//Timestamp int. Soon to be 'long'?
typedef std::chrono::high_resolution_clock::time_point TimeStamp;

//Enumerated Actions. More to follow?
enum InputAction : int { UP, DOWN, LEFT, RIGHT, QUIT };
enum SoundAction : int { PLAY, STOP };

#endif