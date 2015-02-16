#include "ObjectController.h"

#include <iostream>

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

int ObjectController::getObjectLocationX( const StringID id ) {
    int ret = -1;
    if(player_objects.has(id)) {
        ret = player_objects.get(id).getValue().getX();
    }
    if(game_objects.has(id)) {
        ret = game_objects.get(id).getValue().getX();
    }
    if(background_objects.has(id)) {
        ret = background_objects.get(id).getValue().getX();
    }
    if(hud_objects.has(id)) {
        ret = hud_objects.get(id).getValue().getX();
    }

    return ret;
}

int ObjectController::getObjectLocationY( const StringID id ) {
    int ret = -1;

    if(player_objects.has(id)) {
        ret = player_objects.get(id).getValue().getY();
    }
    if(game_objects.has(id)) {
        ret = game_objects.get(id).getValue().getY();
    }
    if(background_objects.has(id)) {
        ret = background_objects.get(id).getValue().getY();
    }
    if(hud_objects.has(id)) {
        ret = hud_objects.get(id).getValue().getY();
    }

    return ret;
}

std::queue<StringID> ObjectController::queueObjects() {
    std::queue<StringID> ret;

    //The order this is done is important! Background first, then objects, then players, then HUD.
    TableIterator<BackgroundObject> it1 = background_objects.begin();
    while(it1 != background_objects.end()) {
        ret.push(it1.getValue().getID());
        ++it1;
    }
    TableIterator<GameObject> it2 = game_objects.begin();
    while(it2 != game_objects.end()) {
        ret.push(it2.getValue().getID());
        ++it2;
    }
    TableIterator<PlayerObject> it3 = player_objects.begin();
    while(it3 != player_objects.end()) {
        ret.push(it3.getValue().getID());
        ++it3;
    }
    TableIterator<HUDObject> it4 = hud_objects.begin();
    while(it4 != hud_objects.end()) {
        ret.push(it4.getValue().getID());
        ++it4;
    }

    return ret;
}

std::queue<HUDObject> ObjectController::queueDebugs() {
    std::queue<HUDObject> ret;

    TableIterator<HUDObject> it1 = debug_objects.begin();
    while(it1 != debug_objects.end()) {
        ret.push(it1.getValue());
        ++it1;
    }

    return ret;
}