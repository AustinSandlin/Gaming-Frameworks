#ifndef _QUIT_GAME_H
#define _QUIT_GAME_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Game/GameController.h"

class QuitGame :

    public Command {

private:

public:

    QuitGame() {
    }

    ~QuitGame() {
    }

    void run() {
        exit(0);
    }
};

Command * parseQuitGame( StringStream & tokens ) {

    return new QuitGame();
}

#endif
