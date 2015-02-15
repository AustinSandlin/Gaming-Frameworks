#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "../../Common/Base/Object.h"

class GameObject:
    public Object< GameObject > {
        
    private:
        //Location
        int x, y;
        //Whether they have collision or not!
        bool collidable;
    
    public:
        GameObject( const StringID& id, int x, int y, bool collidable ) :
            Object< GameObject >( id ), x( x ), y( y ), collidable( collidable ) {
        }

        void set_collidable( bool val ) {
            collidable = val;
        }

        bool get_collidable() {
            return collidable;
        }
        int get_x() {
            return x;
        }
        int get_y() {
            return y;
        }

};

#endif
