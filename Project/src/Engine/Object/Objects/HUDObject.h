#ifndef _HUDOBJECT_OBJECT_H
#define _HUDOBJECT_OBJECT_H

#include "../../../Common/Base/Object.h"

class HUDObject : public Object {
        
    private:
        //Location
        int x, y;
        int* value;
    
    public:
        HUDObject( const StringID& id, int x, int y ) :
            Object ( id ), x( x ), y( y ) {
            value = NULL;
        }

        int getX() {
            return x;
        }
        int getY() {
            return y;
        }
        int getValue() {
            return *value;
        }

        void updateValue(int* val) {
            value = val;
        }

};

#endif
