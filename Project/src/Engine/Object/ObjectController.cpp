#include "ObjectController.h"

#include <iostream>

void ObjectController::handlePlayerAction( const InputAction& action ) {
    TableIterator<PlayerObject> it = player_objects.begin();
    while(it != player_objects.end()) {
        switch(action) {
            case UP:
                if(canMoveUpPlayer( it.getValue().getID() )) {
                    std::cout << "WENT UP" << std::endl;
                    it.getValue().moveUp();
                }
                else {
                    std::cout << "CAN'T UP" << std::endl;
                }
                break;
            case DOWN:
                if(canMoveDownPlayer( it.getValue().getID() )) {
                    std::cout << "WENT DOWN" << std::endl;
                    it.getValue().moveDown();
                }
                else {
                    std::cout << "CAN'T DOWN" << std::endl;
                }
                break;
            case LEFT:
                if(canMoveLeftPlayer( it.getValue().getID() )) {
                    std::cout << "WENT LEFT" << std::endl;
                    it.getValue().moveLeft();
                }
                else {
                    std::cout << "CAN'T LEFT" << std::endl;
                }
                break;
            case RIGHT:
                if(canMoveRightPlayer( it.getValue().getID() )) {
                    std::cout << "WENT RIGHT" << std::endl;
                    it.getValue().moveRight();
                }
                else {
                    std::cout << "CAN'T RIGHT" << std::endl;
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
    return ret;
}

Queue<StringID> ObjectController::queueObjects() {
    Queue<StringID> ret;

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

    return ret;
}