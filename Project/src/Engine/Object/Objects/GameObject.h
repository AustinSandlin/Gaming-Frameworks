#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "../../../Common/Base/Object.h"

class GameObject : public Object {
        
    private:
        //Location
        int x, y;
        //Whether they have collision or not!
        bool collidable;
    
    public:
        GameObject( const StringID& id, int x, int y, bool collidable ) :
            Object ( id ), x( x ), y( y ), collidable( collidable ) {
        }

        void setCollidable( bool val ) {
            collidable = val;
        }

        bool getCollidable() {
            return collidable;
        }
        int getX() {
            return x;
        }
        int getY() {
            return y;
        }

};

#endif
