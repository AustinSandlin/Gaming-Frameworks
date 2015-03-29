#include "GameController.h"

AudioController& GameController::audio_controller = AudioController::instance();
InputController& GameController::input_controller = InputController::instance();
ObjectController& GameController::object_controller = ObjectController::instance();
RenderController& GameController::render_controller = RenderController::instance();
GameController& GameController::game_controller = GameController::instance();

void GameController::renderDisplayCallback() {
    object_controller.drawObjects();
}

void GameController::reshapeCallback(int width, int height) {
    // This keeps the game in the entire screen and otherwise does not change
    // anything when the window is reshaped.
    glViewport(0, 0, width, height); 
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void GameController::handleInputEvent( const StringID& id ) {
    //If there's no mapping, do nothing.
    if(!input_action_table.has(id)) {
        return;
    }
    //Grab the appropriate input action.
    InputAction action = (input_action_table.get(id)).getValue();
    //Do something based on that input.
    if(action == MOVE_UP || action == MOVE_DOWN || action == MOVE_LEFT || action == MOVE_RIGHT) {
        object_controller.handlePlayerAction(action);
    }

    if(action == QUIT) {
        exit(0);
    }
}

void GameController::registerInputAction( const StringID& id, const InputAction action ) {
    input_action_table.add(id, action);
}

void GameController::registerDebugValue( const StringID& id, const DebugValue dval ) {
    if( dval == FPS ) {
        int* temp = &fps;
        object_controller.assignDebugValue( id, temp );
    }
}

void GameController::setupGameLoop(int argc, char **argv) {
    glutInit(&argc, argv);

    render_controller.prepareScreen(WINDOW_X, WINDOW_Y, WINDOW_NAME);

    glutKeyboardFunc(keyboardInputCallback);
    glutKeyboardUpFunc(keyboardUpInputCallback);
    glutMouseFunc(mouseInputCallback);
    glutDisplayFunc(renderDisplayCallback);
    glutTimerFunc(16, updateTimerCallback, 0);
    glutReshapeFunc(reshapeCallback);

    time(&lastTime);
    numFrames = 0;
}

void GameController::updateGameLoop(int value) {

    // Start playing the background music
    if ( !audio_controller.isPlayingSound( "background") ) {
        audio_controller.playSound( "background" );
    }
    
    // Measure speed
    time_t currentTime;
    time(&currentTime);

    numFrames++;

    if ( difftime(currentTime, lastTime) >= 1.0 ){ // If last prinf() was more than 1 sec ago
        // printf and reset timer
        fps = numFrames;
        numFrames = 0;
        lastTime += 1.0;
    }

    //Fetch and process all the input events (by id).
    Queue<StringID> inputEvents = input_controller.queueInputs();
    while(!inputEvents.empty()) {
        handleInputEvent(inputEvents.next());
        inputEvents.pop();
    }
    object_controller.updateEntitys();
    glutPostRedisplay();

    glutTimerFunc(20, updateTimerCallback, 0);
}

void GameController::runGameLoop() {
    glutMainLoop();
}