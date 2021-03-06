#ifndef _PLAYER_OBJECT_H
#define _PLAYER_OBJECT_H

#include "../../../Common/Base/Object.h"
#include <iostream>

class PlayerObject : public Object {
        
    private:

        int velocity;
        Direction dir;
        EntityState state;

    public:
        PlayerObject( const StringID& id, int x, int y, int width, int height ) :
            Object ( id, x, y, height, width ) {
            state = IDLE;
            velocity = 8;
        }

        EntityState getState() {
            return state;
        }
        Direction getDir() {
            return dir;
        }
        int getVelocity() {
            return velocity;
        }
        void setDir(Direction d) {
            dir = d;
        }
        void setState(EntityState s) {
            state = s;
        }

        void move() {
           switch(dir) {
                case UP: y += velocity; break;
                case DOWN: y -= velocity; break;
                case LEFT: x -= velocity; break;
                case RIGHT: x += velocity; break;
                default: break;
            }
        }

        void draw() {
            glBindTexture(GL_TEXTURE_2D, textures[dir]);
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
