#ifndef _BACKGROUND_OBJECT_H
#define _BACKGROUND_OBJECT_H

#include "../../../Common/Base/Object.h"

class BackgroundObject : public Object {
        
    private:
        //Location
        int x, y;
    
    public:
        BackgroundObject( const StringID& id, int x, int y ) :
            Object ( id ), x( x ), y( y ) {
        }

        int getX() {
            return x;
        }
        int getY() {
            return y;
        }

};

#endif
