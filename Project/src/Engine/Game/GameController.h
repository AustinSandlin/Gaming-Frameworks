#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Action.h"

#include <iostream>

class GameController : public Singleton< GameController >{

    private:

        friend class Singleton< GameController >;
        Table< InputAction > input_action_table;

        GameController() {
        }

    public:
        void handleInputEvent( const StringID& id );
        void registerInputAction( const StringID& id, const InputAction action );
        void removeInputAction( const StringID& id );
};

#endif
