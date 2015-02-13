#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H

#include "../../Common/Base/Singleton.h"

#include "ActionTable.h"

namespace Game {

    class GameController : public Singleton< GameController >{

    private:

        friend class Singleton< GameController >;
        Table< InputAction > action_table;

        GameController() {
        }

    public:
        void handleInputEvent( const StringID& id );

    };
}

#endif
