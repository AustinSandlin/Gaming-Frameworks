#include "GameController.h"

void GameController::handleInputEvent( const StringID& id ) {
    InputAction a = (action_table.get(id)).get_value();
    switch(a) {
        case UP:
            break;
        case DOWN:
            break;
        case LEFT:
            break;
        case RIGHT:
            break;
        default:
            break;
    }

}