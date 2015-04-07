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
#include "../Resources/Constants.h"

class Object {

private:

	StringID id;

protected:

    double x, y;
    double height, width; // radius;
    double rotation;
    //bool   isQuad;
    ObjectType type;
    std::vector<int> values;
    std::vector<GLuint> textures;


    Object( StringID oId, ObjectType oType; double oX, double oY, 
            double oWidth, double oHeight, double oRotation ) {

        id = oId;
        type = oType;
        x = oX;
        y = oY;

        if (oWidth < OBJECT_MIN_WIDTH) {
            width = OBJECT_DEFAULT_WIDTH;
        }
        else {
            width = oWidth;
        }

        if (oHeight < OBJECT_MIN_HEIGHT) {
            height = OBJECT_DEFAULT_HEIGHT;
        }
        else {
            height = oHeight;
        }

        /*
        if (oRadius < OBJECT_MIN_RADIUS) {
            radius = OBJECT_DEFAULT_RADIUS;
        }
        else {
            radius = oRadius;
        }*/

        if (oRotation < OBJECT_MIN_ROTATION) {
            rotation = OBJECT_DEFAULT_ROTATION;
        }
        else {
            rotation = oRotation % OBJECT_MAX_ROTATION;
        }

        //isQuad = oIsQuad;
    }

public:
	
    StringID getID() {
        return id;
    }

    double getX() {
        return x;
    }
    
    double getY() {
        return y;
    }

    double getHeight() {
        return height;
    }

    double getWidth() {
        return width;
    }
    /*
    double getRadius() {
        return radius;
    }*/

    double getRotation() {
        return rotation;
    }
    /*
    bool isQuad() {
        return isQuad;
    }*/

    ObjectType getType() {
        return type;
    }

    void addTexture(GLuint id) {
        textures.push_back(id);
    }

    void setValue(int value, int index) {
        while ((values.size() - 1) < index) {
            values.push_back(OBJECT_NULL_VALUE);
        }

        values[index] = value;
    }
};

#endif
