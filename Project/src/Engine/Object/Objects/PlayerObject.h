#ifndef _PLAYER_OBJECT_H
#define _PLAYER_OBJECT_H

#include "../../../Common/Base/Object.h"
#include <iostream>

class PlayerObject : public Object {
        
    private:
        enum Direction{ UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3 };

        //Location
        int x, y;
        Direction direction;

    public:
        PlayerObject( const StringID& id, int x, int y ) :
            Object ( id ), x( x ), y( y ) {
            direction = UP;
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
            direction = UP;
            ++y;
        }
        void moveDown() {
            direction = DOWN;
            --y;
        }
        void moveLeft() {
            direction = LEFT;
            --x;
        }
        void moveRight() {
            direction = RIGHT;
            ++x;
        }

        void draw( ) {
            // std::cout << "drawing: " << textures[direction] << std::endl;
            glBindTexture(GL_TEXTURE_2D, textures[direction]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

            int coord_x = x;
            int coord_y = y;

            worldCordToScreenCord(coord_x, coord_y);

            int coord_width;
            int coord_height;

            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &coord_width);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &coord_height);

            glBegin(GL_QUADS);
                glTexCoord2d(0, 1);
                glVertex2i( coord_x, coord_y );
                glTexCoord2d(1, 1);
                glVertex2i( coord_x+coord_width, coord_y );
                glTexCoord2d(1, 0);
                glVertex2i( coord_x+coord_width, coord_y+coord_height );
                glTexCoord2d(0, 0);
                glVertex2i( coord_x, coord_y+coord_height );
            glEnd();
        }
};

#endif
