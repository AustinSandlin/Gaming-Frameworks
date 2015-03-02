#ifndef _OBJECT_H
#define _OBJECT_H

#if __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include "Types.h"

class Object {

private:

	StringID id;

protected:

    int x, y;
    int height, width;

    std::vector<GLuint> textures;

    Object( StringID id, int x, int y, int height, int width ) : id { id }, x { x }, y { y }, height { height }, width { width } {
    }

public:
	
    StringID getID() const {
        return id;
    }

    int getX() {
        return x;
    }
    
    int getY() {
        return y;
    }

    int getHeight() {
        return height;
    }

    int getWidth() {
        return width;
    }

    StringID getID() {
        return id;
    }

    void addTexture(GLuint id) {
        textures.push_back(id);
    }
};

#endif
