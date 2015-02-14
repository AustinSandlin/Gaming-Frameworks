#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Types/Types.h"

#include "../Object/ObjectController.h"

#include <iostream>

class GameController : public Singleton< GameController >{

    private:

        friend class Singleton< GameController >;
        static ObjectController& object_controller;
    
        Table< InputAction > input_action_table;

        GameController() {
        }

    public:
        void handleInputEvent( const StringID& id );
        void registerInputAction( const StringID& id, const InputAction action );
        void removeInputAction( const StringID& id );
};

#endif
