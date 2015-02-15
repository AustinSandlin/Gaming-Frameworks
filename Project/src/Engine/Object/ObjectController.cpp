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

void ObjectController::registerGameObject( const StringID& id, GameObject go ) {
    game_objects.add( id, go );
}

void ObjectController::registerPlayerObject( const StringID& id, PlayerObject po ) {
    player_objects.add( id, po );
}

bool ObjectController::canMoveUpPlayer( const StringID id ) {
    bool coll = false;

    PlayerObject player = player_objects.get( id ).getValue();

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.getValue().get_x() == player.get_x() &&
           it.getValue().get_y() == (player.get_y()+1)) {
            coll = it.getValue().get_collidable();
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
        if(it.getValue().get_x() == player.get_x() &&
           it.getValue().get_y() == (player.get_y()-1)) {
            coll = it.getValue().get_collidable();
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
        if(it.getValue().get_x() == (player.get_x()-1) &&
           it.getValue().get_y() == player.get_y()) {
            coll = it.getValue().get_collidable();
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
        if(it.getValue().get_x() == (player.get_x()+1) &&
           it.getValue().get_y() == player.get_y()) {
            coll = it.getValue().get_collidable();
        }
        ++it;
    }

    return !coll;
}