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
enum InputAction : int { UP, DOWN, LEFT, RIGHT, QUIT };
enum SoundAction : int { PLAY, STOP };
enum DebugValue : int { FPS };

/*
enum TypeName : int { BOOLEAN, CHAR, SHORT, INT, LONG };
=======
enum TypeName : int {
	BOOLEAN_TYPE,
	CHARACTER_TYPE,
	SHORT_TYPE,
	INTEGER_TYPE,
	LONG_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE
};
>>>>>>> Stashed changes
union TypeValue {
	bool	Boolean;
	char	Character;
	short	Short;
	int		Integer;
	long	Long;
	float	Float;
	double	Double;
};
*/

#endif