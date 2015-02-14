#include "GameController.h"

void GameController::handleInputEvent( const StringID& id ) {
    //If there's no mapping, do nothing.
    if(!input_action_table.has(id)) {
        return;
    }
    //Grab the appropriate input action.
    InputAction a = (input_action_table.get(id)).get_value();
    //Do something based on that input.
    switch(a) {
        case UP:
            std::cout << "UP" << std::endl;
            break;
        case DOWN:
            std::cout << "DOWN" << std::endl;
            break;
        case LEFT:
            std::cout << "LEFT" << std::endl;
            break;
        case RIGHT:
            std::cout << "RIGHT" << std::endl;
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