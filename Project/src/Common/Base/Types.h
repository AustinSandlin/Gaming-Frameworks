#ifndef _TYPES_H
#define _TYPES_H

#include <string>

//A few string things. StringID is unique identifier based on a string hash.
typedef size_t StringID;
//Easier use of string without calling std:: everywhere.
typedef std::string String;

//Timestamp int. Soon to be 'long'?
typedef long TimeStamp;

//Enumerated Actions. More to follow?
enum Direction : int { UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };
enum InputAction : int { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, QUIT, ATTACK };
enum SoundAction : int { PLAY, STOP };
enum DebugValue : int { FPS, PLAYER_HEALTH };
enum EntityState : int { MOVING, IDLE, ATTACKING };
enum AIType : int { WANDER };

#endif