#ifndef _BIND_HUD_OBJECT_H
#define _BIND_HUD_OBJECT_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"
#include "../../../Common/Resources/Strings.h"

#include "../Objects/HUDObject.h"
#include "../ObjectController.h"

class BindHUDObject :

    public Command {

private:

    String name;
    String variable;


public:

    BindHUDObject( String name, String variable ) {
        this->name = name;
        this->variable = variable;
    }

    ~BindHUDObject() {
    }

    void run() {

        // 
        static Strings & strings = Strings::instance();
        static GameController & game_controller = GameController::instance(); 

        // 
        StringID id = strings.intern( name );
        game_controller.registerValue( id, variable );
    }
};

Command * parseBindHUDObject( StringStream & tokens ) {

    // 
    String name, variable;

    // 
    tokens >> name;
    if ( name.empty() ) {
        return NULL;
    }

    // 
    tokens >> variable;
    if ( variable.empty() ) {
        return NULL;
    }

    // 
    return new BindHUDObject( name, variable );
}

#endif
