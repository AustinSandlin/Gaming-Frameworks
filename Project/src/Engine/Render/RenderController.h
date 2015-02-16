#ifndef _RENDER_CONTROLLER_H
#define _RENDER_CONTROLLER_H

#if __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Types.h"
#include "Image.h"

#include "../Object/ObjectController.h"

#include <iostream>

static ObjectController& object_controller = ObjectController::instance();

const int PIXEL_X = 32;
const int PIXEL_Y = 32;

class RenderController:
	
	public Singleton< RenderController > {

	private:

		friend class Singleton< RenderController >;
		Table< GLuint > texture_paths;

		RenderController() {

		}

		void worldCordToScreenCord(int& x, int& y) {
			x *= PIXEL_X;
			y *= PIXEL_Y;
		}

        Image* loadBMP(const char* filename);

		void renderObjects( std::queue< StringID > objs );
		void renderDebugs( std::queue< HUDObject > huds );
	
	public:

		void registerObjectTexture( StringID, String );

		void prepareScreen( int x, int y, String name );
		void renderScreen( std::queue< StringID > objs, std::queue< HUDObject > huds );
};

#endif
