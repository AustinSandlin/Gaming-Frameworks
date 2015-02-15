#include "RenderController.h"

void RenderController::prepareScreen( int x, int y, String name ) {
	glutInitWindowSize(x, y);
	glutCreateWindow(name.c_str());
	glClearColor(1.0, 1.0, 1.0, 0);
}

void RenderController::renderScreen( ) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutSwapBuffers();
}