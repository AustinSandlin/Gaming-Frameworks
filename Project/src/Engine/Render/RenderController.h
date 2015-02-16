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

class RenderController:
	
	public Singleton< RenderController > {

	private:

		friend class Singleton< RenderController >;
		Table< String > texture_paths;

		RenderController() {

		}

		void worldCordToScreenCord(int& x, int& y) {
			x *= 16;
			y *= 16;
		}

        Image* loadBMP(const char* filename);

	public:

		void registerObjectTexture( StringID, String );

		void prepareScreen( int x, int y, String name );
		void renderScreen( Queue< StringID > objs );
};

#endif
