#ifndef _BACKGROUND_OBJECT_H
#define _BACKGROUND_OBJECT_H

#include "../../../Common/Base/Object.h"

#include <iostream>

class BackgroundObject : public Object {
        
    private:
    
    public:
        BackgroundObject( const StringID& id, int x, int y, int width, int height ) :
            Object ( id, x, y, height, width ) {
        }

        void draw( ) {

            glBindTexture(GL_TEXTURE_2D, textures[0]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            int width;
            int height;

            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);

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
