#include "ObjectController.h"

RenderController& ObjectController::render_controller = RenderController::instance();

void ObjectController::handlePlayerAction( const InputAction& action ) {
    static AudioController& audio_controller = AudioController::instance();

    TableIterator<PlayerObject> it = player_objects.begin();
    while(it != player_objects.end()) {
        switch(action) {
            case UP:
                if(canMoveUpPlayer( it.getValue().getID() )) {
                    it.getValue().moveUp();
                }
                else {
                    audio_controller.playSound( "../Sounds/buzzer.wav" );
                }
                break;
            case DOWN:
                if(canMoveDownPlayer( it.getValue().getID() )) {
                    it.getValue().moveDown();
                }
                else {
                    audio_controller.playSound( "../Sounds/buzzer.wav" );
                }
                break;
            case LEFT:
                if(canMoveLeftPlayer( it.getValue().getID() )) {
                    it.getValue().moveLeft();
                }
                else {
                    audio_controller.playSound( "../Sounds/buzzer.wav" );
                }
                break;
            case RIGHT:
                if(canMoveRightPlayer( it.getValue().getID() )) {
                    it.getValue().moveRight();
                }
                else {
                    audio_controller.playSound( "../Sounds/buzzer.wav" );
                }
                break;
            default:
                break;
        }
        ++it;
    }
}

void ObjectController::registerObjectTexture( const StringID& id, const String path ) {
    GLuint textureID = render_controller.loadBMP(path.c_str());

    if(background_objects.has(id)) {
        background_objects.get(id).getValue().addTexture(textureID);
    }
    else if(game_objects.has(id)) {
        game_objects.get(id).getValue().addTexture(textureID);
    }
    else if(player_objects.has(id)) {
        player_objects.get(id).getValue().addTexture(textureID);
    }
    else if(hud_objects.has(id)) {
        hud_objects.get(id).getValue().addTexture(textureID);
    }
}

void ObjectController::registerBackgroundObject( const StringID& id, BackgroundObject bo ) {
    background_objects.add( id, bo );
}

void ObjectController::registerPlayerObject( const StringID& id, PlayerObject po ) {
    player_objects.add( id, po );
}

void ObjectController::registerGameObject( const StringID& id, GameObject go ) {
    game_objects.add( id, go );
}

void ObjectController::registerHUDObject( const StringID& id, HUDObject ho ) {
    hud_objects.add( id, ho );
}

void ObjectController::registerDebugObject( const StringID& id, HUDObject ho ) {
    debug_objects.add( id, ho );
}

void ObjectController::assignDebugValue( const StringID& id, int* ptr ) {
    if(debug_objects.has(id)) {
        debug_objects.get(id).getValue().updateValue(ptr);
    }
}

bool ObjectController::canMoveUpPlayer( const StringID id ) {
    bool coll = false;

    PlayerObject player = player_objects.get( id ).getValue();

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.getValue().getX() == player.getX() &&
           it.getValue().getY() == (player.getY()+1)) {
            coll = it.getValue().getCollidable();
        }
        ++it;
    }

    return !coll;
}

bool ObjectController::canMoveDownPlayer( const StringID id ) {
    bool coll = false;

    PlayerObject player = player_objects.get( id ).getValue();

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.getValue().getX() == player.getX() &&
           it.getValue().getY() == (player.getY()-1)) {
            coll = it.getValue().getCollidable();
        }
        ++it;
    }

    return !coll;
}

bool ObjectController::canMoveLeftPlayer( const StringID id ) {
    bool coll = false;

    PlayerObject player = player_objects.get( id ).getValue();

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.getValue().getX() == (player.getX()-1) &&
           it.getValue().getY() == player.getY()) {
            coll = it.getValue().getCollidable();
        }
        ++it;
    }

    return !coll;
}

bool ObjectController::canMoveRightPlayer( const StringID id ) {
    bool coll = false;

    PlayerObject player = player_objects.get( id ).getValue();

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.getValue().getX() == (player.getX()+1) &&
           it.getValue().getY() == player.getY()) {
            coll = it.getValue().getCollidable();
        }
        ++it;
    }

    return !coll;
}

void ObjectController::drawObjects() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    TableIterator<BackgroundObject> it1 = background_objects.begin();
    while(it1 != background_objects.end()) {
        it1.getValue().draw();
        ++it1;
    }
    TableIterator<GameObject> it2 = game_objects.begin();
    while(it2 != game_objects.end()) {
        it2.getValue().draw();
        ++it2;
    }
    TableIterator<PlayerObject> it3 = player_objects.begin();
    while(it3 != player_objects.end()) {
        it3.getValue().draw();
        ++it3;
    }
    TableIterator<HUDObject> it4 = hud_objects.begin();
    while(it4 != hud_objects.end()) {
        it4.getValue().draw();
        ++it4;
    }
    TableIterator<HUDObject> it5 = debug_objects.begin();
    while(it5 != debug_objects.end()) {
        it5.getValue().draw();
        ++it5;
    }

    glutSwapBuffers();
}
