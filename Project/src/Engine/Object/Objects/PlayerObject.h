#ifndef _PLAYER_OBJECT_H
#define _PLAYER_OBJECT_H

#include "../../../Common/Base/Object.h"

class PlayerObject : public Object {
        
    private:
        //Location
        int x, y;
    
    public:
        PlayerObject( const StringID& id, int x, int y ) :
            Object ( id ), x( x ), y( y ) {
        }

        //Get location methods
        int getX() {
            return x;
        }
        int getY() {
            return y;
        }

        //Functions for player movement.
        void moveUp() {
            ++y;
        }
        void moveDown() {
            --y;
        }
        void moveRight() {
            ++x;
        }
        void moveLeft() {
            --x;
        }

};

#endif
