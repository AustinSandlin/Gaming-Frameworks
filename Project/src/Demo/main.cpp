/* Author: Austin Sandlin
 * Title: Primary Demo Shell
 * Date Last Modified: 01/28/15
 * Description: Registers callbacks with OpenGL. Attempts to connect the
 *              callbacks to an input listener class.
 */

#include "../Engine/Input/InputController.h"

#if defined(_WIN32) || defined(WIN32)   
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

bool useKeyUp;
InputController* ic;

void init() {
    // Set these preferences for the window. (RBG color, double buffer, 3D).
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // Window size 600x600.
    glutInitWindowSize(600, 600);
    // Set the title.
    glutCreateWindow("Game Engine Demo");

    // Enable 3D depth.
    glEnable(GL_DEPTH_TEST);

    // Get the input controller instance.
    //ic = &(ic->GetInstance());

    // Default to !useKeyUp;
    useKeyUp = false;

    // Set the default background color to white.
    glClearColor(1.0, 1.0, 1.0, 0);
}

void display() {
    // Clear the color and the Z-Buffer components.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Load the identity matrix into the projection matrix.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Load the identity matrix into the modelview matrix.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Figure out the aspect ratio.
    // int winWidth = glutGet(GLUT_WINDOW_WIDTH);
    // int winHeight = glutGet(GLUT_WINDOW_HEIGHT);

    // Show it to the user.
    glutSwapBuffers();
}

// Callback for when keys are pressed down.
void keyDown(unsigned char key, int x, int y) {
    if(!useKeyUp) {
        //ic.keyDown(key);
    }
}

// Callback for when keys are released
void keyUp(unsigned char key, int x, int y) {
    if(useKeyUp) {
        //ic.keyUp(key);
    }
}

// Callback for when the mouse button is pressed.
void mouse(int button, int state, int x, int y) {
    //ic.mouse(button, state, x, y);
}

// Callback called when our timer goes off.  Tell the chess object
// what the application time is in milliseconds.
void timerFunction(int value) {
    // Register a new timer.
    glutTimerFunc(20, timerFunction, 0);
}

int main(int argc, char **argv) {
    // Init glut
    glutInit(&argc, argv);

    // Do initialization stuff for the demo.
    init();

    // Register all our callbacks.
    glutDisplayFunc(display);
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutMouseFunc(mouse);

    // Register our first timer callback.
    glutTimerFunc(20, timerFunction, 0);

    // Start the glut event loop.
    glutMainLoop();

    return 0;
}