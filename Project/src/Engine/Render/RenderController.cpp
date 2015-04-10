#include "RenderController.h"

void RenderController::prepareScreen( int x, int y, String name ) {
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(x, y);
    glutInitWindowPosition(WINDOW_OFFSET_X, WINDOW_OFFSET_Y);
    glutCreateWindow(name.c_str());
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glEnable(GL_BLEND);
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    gluOrtho2D(ORTHO_LEFT, ORTHO_RIGHT, ORTHO_BOTTOM, ORTHO_TOP);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GLuint RenderController::loadBMP(const char* filename) {
    ifstream input;
    input.open(filename, ifstream::binary);
    if(!input) {
        input.clear();
        exit(1);
    }

    input.ignore(10);

    char buffer[4];
    input.read(buffer, 4);
    int dataOffset = (int)(((unsigned char)buffer[3] << 24) |
                          ((unsigned char)buffer[2] << 16) |
                          ((unsigned char)buffer[1] << 8) |
                          (unsigned char)buffer[0]);
    
    //Read the header
    input.read(buffer, 4);
    int headerSize = (int)(((unsigned char)buffer[3] << 24) |
                          ((unsigned char)buffer[2] << 16) |
                          ((unsigned char)buffer[1] << 8) |
                          (unsigned char)buffer[0]);

    if( headerSize != 40 ) {
        input.close();
        input.clear();
        //cout << "wrong header size (need 56 bit header)" << endl;
        exit(1);
    }

    int width;
    int height;
    input.read(buffer, 4);
    width = (int)(((unsigned char)buffer[3] << 24) |
            ((unsigned char)buffer[2] << 16) |
            ((unsigned char)buffer[1] << 8) |
            (unsigned char)buffer[0]);
    input.read(buffer, 4);
    height = (int)(((unsigned char)buffer[3] << 24) |
            ((unsigned char)buffer[2] << 16) |
            ((unsigned char)buffer[1] << 8) |
            (unsigned char)buffer[0]);

    //Read the data
    int bytesPerRow = (width * 4);
    int size = bytesPerRow * height;
    char* pixels = new char[size];
    input.seekg(dataOffset, ios_base::beg);
    input.read(pixels, size);
    
    //Get the data into the right format
    for(int y = 0; y < height; ++y) {
        for(int x = 0; x < width; ++x) {
            for(int c = 0; c < 3; ++c) {
                //Swap the blue and red bytes. (BGRA -> RGBA)
                pixels[bytesPerRow * y + 4 * x + 0] ^= pixels[bytesPerRow * y + 4 * x + 2];
                pixels[bytesPerRow * y + 4 * x + 2] ^= pixels[bytesPerRow * y + 4 * x + 0];
                pixels[bytesPerRow * y + 4 * x + 0] ^= pixels[bytesPerRow * y + 4 * x + 2];
            }
        }
    }

    input.close();
    input.clear();

    // Load new-fangled texture.
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 width, height,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 pixels);

    //Return the texture id for purposes.
    return textureID;
}
