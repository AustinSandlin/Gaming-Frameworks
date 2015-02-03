/* Author: Austin Sandlin
 * Title: Primary Demo Shell
 * Date Last Modified: 02/2/15
 * Description: Registers callbacks with OpenGL. Attempts to connect the
 *              callbacks to an input listener class.
 */

#include "../Engine/Input/InputController.h"
#include "../Engine/Input/Events/InputUpdate.h"
 #include "../Engine/Input/Events/InputCommand.h"
#include <iostream>
#include <sstream>

#if defined(_WIN32) || defined(WIN32)   
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

void editFunc() {
    bool editMode = true;
    while(editMode) {
        istringstream instream;
        string inputStr;
        
        cout << "Console: ";
        getline(cin, inputStr);

        instream.str(inputStr);
        instream >> inputStr;
        
        if(inputStr == "exit") {
            editMode = false;
        }
        else if(inputStr == "add") {
            instream >> inputStr;
            if(inputStr == "pane") {
                int x, y;
                instream >> x >> y;
                // Make a new Pane object here?
            }
            else if(inputStr == "object") {
                double x, y, z;
                instream >> x >> y >> z;
                // Make a new Object here?
            }
        }
    }

    return;
}

void game() {
    return;
}

void init() {
    // Set these preferences for the window. (RBG color, double buffer, 3D).
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // Window size 600x600.
    glutInitWindowSize(600, 600);
    // Set the title.
    glutCreateWindow("Game Engine Demo");
    // Enable 3D depth.
    glEnable(GL_DEPTH_TEST);

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

    // Show changes to the user.
    glutSwapBuffers();
}

// Callback for when keys are pressed down.
void keyboard(unsigned char key, int x, int y) {
    static auto & controller = InputController::GetInstance();
    switch(key) {
        case '~': editFunc();
                  break;
        case 27: exit(0);
                 break;
        case 'a': controller.HandleEvent( new InputUpdate() );
                  break;
        default: controller.HandleEvent( new InputCommand( key ) );
    }
}

// Callback called when our timer goes off. 
void timerFunction(int value) {
    // Input is handled from the keyboard callback.

    // Update game state.
    game();

    // Render the display.
    glutPostRedisplay();

    // Register a new timer.
    glutTimerFunc(20000, timerFunction, 0);
}

int main(int argc, char **argv) {
    // Init glut
    glutInit(&argc, argv);

    // Do initialization stuff for the demo.
    init();

    // Register all our callbacks.
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Register our first timer callback.
    glutTimerFunc(20, timerFunction, 0);

    // Start the glut event loop.
    glutMainLoop();

    return 0;
}