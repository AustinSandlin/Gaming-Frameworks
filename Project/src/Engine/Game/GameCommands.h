#ifndef _GAME_COMMANDS_H
#define _GAME_COMMANDS_H

#include "Commands/QuitGame.h"

Command * parseGameCommand( StringStream & tokens ) {
    return parseQuitGame( tokens );

    return NULL;
}

#endif
