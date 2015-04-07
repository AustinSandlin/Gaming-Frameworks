#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#include <string>

using namespace std;


// Loader values for the edges of input:
const string LOADER_START_STRING = "start";
const string LOADER_END_STRING   = "end";

// Primary loader commands
const string LOADER_COMMAND_1 = "sound";
const string LOADER_COMMAND_2 = "texture";
const string LOADER_COMMAND_3 = "input";
const string LOADER_COMMAND_4 = "playerobject";
const string LOADER_COMMAND_5 = "aiobject";
const string LOADER_COMMAND_6 = "gameobject";
const string LOADER_COMMAND_7 = "backgroundobject";
const string LOADER_COMMAND_8 = "hudobject";
const string LOADER_COMMAND_9 = "debug";

// Loader subcommands
const string LOADER_COMMAND_A = "add";
const string LOADER_COMMAND_B = "value";

// Loader recognized AI types
const string LOADER_AI_TYPE_1 = "wander";

// Loader recognized action types
const string LOADER_ACTION_TYPE_1 = "move_up";
const string LOADER_ACTION_TYPE_2 = "move_down";
const string LOADER_ACTION_TYPE_3 = "move_left";
const string LOADER_ACTION_TYPE_4 = "move_right";
const string LOADER_ACTION_TYPE_5 = "quit";
const string LOADER_ACTION_TYPE_6 = "attack";

// Loader recognized debug value types
const string LOADER_DEBUG_VALUE_TYPE_1 = "fps";
const string LOADER_DEBUG_VALUE_TYPE_2 = "playerhealth";


// Default window dimensions
const int WINDOW_OFFSET_X = 0;
const int WINDOW_OFFSET_Y = 0;
const int WINDOW_X = 600;
const int WINDOW_Y = 600;
const string WINDOW_NAME = "Demo";

// World coordinates
const int ORTHO_LEFT = 0;
const int ORTHO_RIGHT = 1000;
const int ORTHO_BOTTOM = 0;
const int ORTHO_TOP = 1000;

// Object constants
const double OBJECT_MIN_WIDTH = 0.0;
const double OBJECT_DEFAULT_WIDTH = 1.0;
const double OBJECT_MIN_HEIGHT = 0.0;
const double OBJECT_DEFAULT_HEIGHT = 1.0;
const double OBJECT_MIN_RADIUS = 0.0;
const double OBJECT_DEFAULT_RADIUS = 1.0;
const double OBJECT_MIN_ROTATION = 0.0;
const double OBJECT_DEFAULT_ROTATION = 0.0;
const double OBJECT_MAX_ROTATION = 360.0;

const double OBJECT_NULL_VALUE = -1;


#endif 
