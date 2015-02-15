#ifndef _TYPES_H
#define _TYPES_H

#include <string>

//A few string things. StringID is unique identifier based on a string hash.
typedef int StringID;
//Easier use of string without calling std:: everywhere.
typedef std::string String;

//Timestamp int. Soon to be 'long'?
typedef long TimeStamp;

//Enumerated Actions. More to follow?
enum InputAction : int { UP, DOWN, LEFT, RIGHT, QUIT };
enum SoundAction : int { PLAY, STOP };

enum TypeName : int { BOOLEAN, CHAR, SHORT, INT, LONG };
union TypeValue {
};

#endif