#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "../../../Common/Base/Object.h"

class GameObject : public Object {
        
    private:

        //Whether they have collision or not!
        bool collidable;
    
    public:
        GameObject( const StringID& id, int x, int y, int width, int height, bool collidable ) :
            Object ( id, x, y, height, width ), collidable( collidable ) {
        }

        void setCollidable( bool val ) {
            collidable = val;
        }

        bool getCollidable() {
            return collidable;
        }

        void draw( ) {
            glBindTexture(GL_TEXTURE_2D, textures[0]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            glBegin(GL_QUADS);
                glTexCoord2d(0, 1);
                glVertex2i( x, y );
                glTexCoord2d(1, 1);
                glVertex2i( x+width, y );
                glTexCoord2d(1, 0);
                glVertex2i( x+width, y+height );
                glTexCoord2d(0, 0);
                glVertex2i( x, y+height );
            glEnd();
        }
};

#endif
