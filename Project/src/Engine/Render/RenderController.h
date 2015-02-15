#ifndef _RENDER_CONTROLLER_H
#define _RENDER_CONTROLLER_H

#if defined(_WIN32) || defined(WIN32)   
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Types.h"

class RenderController:
	
	public Singleton< RenderController > {

	private:

		friend class Singleton< RenderController >;
		Table< String > texture_paths;

		RenderController() {

		}

	public:

		void registerObjectTexture( StringID, String );

		void prepareScreen( int x, int y, String name );
		void renderScreen( );
};

#endif
