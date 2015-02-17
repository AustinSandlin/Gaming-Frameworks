#include "ObjectController.h"

#include <iostream>

RenderController& ObjectController::render_controller = RenderController::instance();

void ObjectController::handlePlayerAction( const InputAction& action ) {
    TableIterator<PlayerObject> it = player_objects.begin();
    while(it != player_objects.end()) {
        switch(action) {
            case UP:
                if(canMoveUpPlayer( it.getValue().getID() )) {
                    it.getValue().moveUp();
                }
                else {
                }
                break;
            case DOWN:
                if(canMoveDownPlayer( it.getValue().getID() )) {
                    it.getValue().moveDown();
                }
                else {
                }
                break;
            case LEFT:
                if(canMoveLeftPlayer( it.getValue().getID() )) {
                    it.getValue().moveLeft();
                }
                else {
                }
                break;
            case RIGHT:
                if(canMoveRightPlayer( it.getValue().getID() )) {
                    it.getValue().moveRight();
                }
                else {
                }
                break;
            default:
                break;
        }
        ++it;
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
        it1.getValue().draw(render_controller.getTextureID(it1.getValue().getID()));
        ++it1;
    }
    TableIterator<GameObject> it2 = game_objects.begin();
    while(it2 != game_objects.end()) {
        it2.getValue().draw(render_controller.getTextureID(it2.getValue().getID()));
        ++it2;
    }
    TableIterator<PlayerObject> it3 = player_objects.begin();
    while(it3 != player_objects.end()) {
        it3.getValue().draw(render_controller.getTextureID(it3.getValue().getID()));
        ++it3;
    }
    TableIterator<HUDObject> it4 = hud_objects.begin();
    while(it4 != hud_objects.end()) {
        it4.getValue().draw(render_controller.getTextureID(it4.getValue().getID()));
        ++it4;
    }
    TableIterator<HUDObject> it5 = debug_objects.begin();
    while(it5 != debug_objects.end()) {
        it5.getValue().draw(render_controller.getTextureID(it5.getValue().getID()));
        ++it5;
    }

    glutSwapBuffers();
}

// void ObjectController::drawObject( const StringID id, GLuint texid ) {
//     bool drawn = false;

//     TableIterator<BackgroundObject> it1 = background_objects.begin();
//     while(it1 != background_objects.end() && !drawn) {
//         if(it1.getValue().getID() == id) it1.getValue().draw(texid);
//         ++it1;
//     }
//     TableIterator<GameObject> it2 = game_objects.begin();
//     while(it2 != game_objects.end() && !drawn) {
//         if(it2.getValue().getID() == id) it2.getValue().draw(texid);
//         ++it2;
//     }
//     TableIterator<PlayerObject> it3 = player_objects.begin();
//     while(it3 != player_objects.end() && !drawn) {
//         if(it3.getValue().getID() == id) it3.getValue().draw(texid);
//         ++it3;
//     }
//     TableIterator<HUDObject> it4 = hud_objects.begin();
//     while(it4 != hud_objects.end() && !drawn) {
//         if(it4.getValue().getID() == id) it4.getValue().draw(texid);
//         ++it4;
//     }
//     TableIterator<HUDObject> it5 = debug_objects.begin();
//     while(it5 != debug_objects.end() && !drawn) {
//         if(it5.getValue().getID() == id) it5.getValue().draw(texid);
//         ++it5;
//     }
// }

// std::queue<StringID> ObjectController::queueObjects() {
//     std::queue<StringID> ret;

//     //The order this is done is important! Background first, then objects, then players, then HUD.
//     TableIterator<BackgroundObject> it1 = background_objects.begin();
//     while(it1 != background_objects.end()) {
//         ret.push(it1.getValue().getID());
//         ++it1;
//     }
//     TableIterator<GameObject> it2 = game_objects.begin();
//     while(it2 != game_objects.end()) {
//         ret.push(it2.getValue().getID());
//         ++it2;
//     }
//     TableIterator<PlayerObject> it3 = player_objects.begin();
//     while(it3 != player_objects.end()) {
//         ret.push(it3.getValue().getID());
//         ++it3;
//     }
//     TableIterator<HUDObject> it4 = hud_objects.begin();
//     while(it4 != hud_objects.end()) {
//         ret.push(it4.getValue().getID());
//         ++it4;
//     }

//     return ret;
// }

// std::queue<StringID> ObjectController::queueDebugs() {
//     std::queue<StringID> ret;

//     TableIterator<HUDObject> it1 = debug_objects.begin();
//     while(it1 != debug_objects.end()) {
//         ret.push(it1.getValue().getID());
//         ++it1;
//     }

//     return ret;
// }