#include "GameController.h"

void GameController::handleInputEvent( const StringID& id ) {
    InputAction a = (input_action_table.get(id)).get_value();
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

void GameController::registerInputAction( const StringID& id, const InputAction action ) {
    input_action_table.add(id, action);
}

void GameController::removeInputAction( const StringID& id) {
    input_action_table.remove(id);
}