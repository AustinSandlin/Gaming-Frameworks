#include "GameController.h"

InputController& GameController::input_controller = InputController::instance();
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

void GameController::setupGameLoop() {
    glutKeyboardFunc(keyboardInputCallback);
    glutMouseFunc(mouseInputCallback);
    time(&lastTime);
    numFrames = 0;
}

void GameController::runGameLoop() {
    // Measure speed
    time_t currentTime;
    time(&currentTime);

    numFrames++;

    if ( difftime(currentTime, lastTime) >= 1.0 ){ // If last prinf() was more than 1 sec ago
        // printf and reset timer
        // std::cout << numFrames << std::endl;
        numFrames = 0;
        lastTime += 1.0;
    }

    //Fetch and process all the input events (by id).
    Queue<StringID> inputEvents = input_controller.processInput();
    while(!inputEvents.empty()) {
        handleInputEvent(inputEvents.next());
        inputEvents.pop();
    }
}