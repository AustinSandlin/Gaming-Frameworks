#include "ObjectController.h"

#include <iostream>

void ObjectController::handlePlayerAction( const InputAction& action ) {
    switch(action) {
        case UP:
            if(canMoveUpPlayer()) {
                std::cout << "WENT UP" << std::endl;
                player.moveUp();
            }
            else {
                std::cout << "CAN'T UP" << std::endl;
            }
            break;
        case DOWN:
            if(canMoveDownPlayer()) {
                std::cout << "WENT DOWN" << std::endl;
                player.moveDown();
            }
            else {
                std::cout << "CAN'T DOWN" << std::endl;
            }
            break;
        case LEFT:
            if(canMoveLeftPlayer()) {
                std::cout << "WENT LEFT" << std::endl;
                player.moveLeft();
            }
            else {
                std::cout << "CAN'T LEFT" << std::endl;
            }
            break;
        case RIGHT:
            if(canMoveRightPlayer()) {
                std::cout << "WENT RIGHT" << std::endl;
                player.moveRight();
            }
            else {
                std::cout << "CAN'T RIGHT" << std::endl;
            }
            break;
        default:
            break;
    }
}

void ObjectController::registerGameObject( const StringID& id, GameObject go ) {
    game_objects.add( id, go );
}

bool ObjectController::canMoveUpPlayer() {
    bool coll = false;

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.get_value().get_x() == player.get_x() &&
           it.get_value().get_y() == (player.get_y()+1)) {
            coll = it.get_value().get_collidable();
        }
        ++it;
    }

    return !coll;
}
bool ObjectController::canMoveDownPlayer() {
    bool coll = false;

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.get_value().get_x() == player.get_x() &&
           it.get_value().get_y() == (player.get_y()-1)) {
            coll = it.get_value().get_collidable();
        }
        ++it;
    }

    return !coll;
}
bool ObjectController::canMoveLeftPlayer() {
    bool coll = false;

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.get_value().get_x() == (player.get_x()-1) &&
           it.get_value().get_y() == player.get_y()) {
            coll = it.get_value().get_collidable();
        }
        ++it;
    }

    return !coll;
}
bool ObjectController::canMoveRightPlayer() {
    bool coll = false;

    TableIterator<GameObject> it = game_objects.begin();
    while(it != game_objects.end() && !coll) {
        if(it.get_value().get_x() == (player.get_x()+1) &&
           it.get_value().get_y() == player.get_y()) {
            coll = it.get_value().get_collidable();
        }
        ++it;
    }

    return !coll;
}