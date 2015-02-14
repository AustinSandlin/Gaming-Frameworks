#include "GameController.h"

ObjectController& GameController::object_controller = ObjectController::instance();

void GameController::handleInputEvent( const StringID& id ) {
    //If there's no mapping, do nothing.
    if(!input_action_table.has(id)) {
        return;
    }
    //Grab the appropriate input action.
    InputAction action = (input_action_table.get(id)).get_value();
    //Do something based on that input.
    if(action == UP || action == DOWN || action == LEFT || action == RIGHT) {
        object_controller.handlePlayerAction(action);
    }
}

void GameController::registerInputAction( const StringID& id, const InputAction action ) {
    input_action_table.add(id, action);
}

void GameController::removeInputAction( const StringID& id) {
    input_action_table.remove(id);
}