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
#include "Property.h"

const int PIXEL_X = 32;
const int PIXEL_Y = 32;

class Object {

private:

	StringID id;
	Table< Property > properties;

protected:
    std::vector<GLuint> textures;

    Object( StringID id ) : id { id } {
    }

    void worldCordToScreenCord(int& x, int& y) {
        x *= PIXEL_X;
        y *= PIXEL_Y;
    }

public:
	
    StringID getID() const {
        return id;
    }

    void addTexture(GLuint id) {
        textures.push_back(id);
    }

    void addProperty( StringID id, Property property ) {
    	properties.add( id, property );
    }
    void removeProperty( StringID id ) {
    	properties.remove( id );
    }
    bool hasProperty( StringID id ) const {
    	return properties.has( id );
    }
    Property & getProperty( StringID id ) {
		return properties.get( id ).getValue();
    }
};

#endif
