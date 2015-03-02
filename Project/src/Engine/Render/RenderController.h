#ifndef _RENDER_CONTROLLER_H
#define _RENDER_CONTROLLER_H

#if __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Types.h"

#include <fstream>
#include <iostream>

using namespace std;

class RenderController:
	
	public Singleton< RenderController > {

	private:

		friend class Singleton< RenderController >;
		RenderController() {

		}

	public:

        GLuint loadBMP(const char* filename);
		void prepareScreen( int x, int y, String name );
};

#endif
