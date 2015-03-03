#ifndef _HUDOBJECT_OBJECT_H
#define _HUDOBJECT_OBJECT_H

#include "../../../Common/Base/Object.h"

#include <sstream>

using namespace std;

class HUDObject : public Object {
        
    private:
        //Location
        bool debug;

        int* value;
    
    public:
        HUDObject( const StringID& id, int x, int y, int width, int height, bool debug ) :
            Object ( id, x, y, height, width ), debug( debug ) {
            value = NULL;
        }

        int getValue() {
            return *value;
        }

        void updateValue(int* val) {
            value = val;
        }

        void draw( ) {
            if(debug) {
                glDisable(GL_TEXTURE_2D);
                glColor3f(1.0, 1.0, 1.0);
                std::stringstream ss;
                ss << *value;
                String output = ss.str();
                //String output = std::to_string(*value);
                for (unsigned int i = 0; i < output.length(); ++i) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, output[i]);
                }
                glRasterPos2f(x, y);
                glEnable(GL_TEXTURE_2D);
            }
            else {
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
        }
};

#endif
