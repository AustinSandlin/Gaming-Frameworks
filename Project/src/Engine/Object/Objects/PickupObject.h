#ifndef _PICKUP_OBJECT_H
#define _PICKUP_OBJECT_H

#include "../../../Common/Base/Object.h"
#include <iostream>

class PickupObject : public Object {
        
    private:
        Direction dir;
        BuffType buff;
        int value;

    public:
        PickupObject( const StringID& id, int x, int y, int width, int height, BuffType bf, int buffValue ) :
            Object ( id, x, y, height, width ), buff(bf), value(buffValue) {
            dir = DOWN;
        }

        Direction getDir() {
            return dir;
        }
        BuffType getBuff() {
            return buff;
        }
        int getValue() {
            return value;
        }
        void setDir(Direction d) {
            dir = d;
        }

        void draw() {
            glBindTexture(GL_TEXTURE_2D, textures[dir]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            glBegin(GL_QUADS);
                glTexCoord2d(1, 0);
                glVertex2i( x, y );
                glTexCoord2d(0, 0);
                glVertex2i( x+width, y );
                glTexCoord2d(0, 1);
                glVertex2i( x+width, y+height );
                glTexCoord2d(1, 1);
                glVertex2i( x, y+height );
            glEnd();
        }
};

#endif
