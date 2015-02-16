#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H

#if __APPLE__ 
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Types.h"

#include "../../Engine/Input/InputController.h"
#include "../../Engine/Object/ObjectController.h"
#include "../../Engine/Render/RenderController.h"

#include <time.h>
#include <iostream>

class GameController : public Singleton< GameController >{

    private:

        friend class Singleton< GameController >;
        static InputController& input_controller;
        static ObjectController& object_controller;
        static RenderController& render_controller;
        static GameController& game_controller;

        time_t lastTime;
        int numFrames;
        int fps;
    
        Table< InputAction > input_action_table;

        GameController() {
            fps = 0;
        }

        static void keyboardInputCallback(unsigned char key, int x, int y) {
            input_controller.queueKeyboardEvent(key, x, y);
        }

        static void mouseInputCallback(int button, int state, int x, int y) {
            input_controller.queueMouseEvent(button, state, x, y);
        }

        static void updateTimerCallback(int val) {
            game_controller.updateGameLoop(val);
        }

        static void renderDisplayCallback();

    public:
        void handleInputEvent( const StringID& id );
        void registerInputAction( const StringID& id, const InputAction action );
        void registerDebugValue( const StringID& id, const DebugValue dval );

        void setupGameLoop(int argc, char **argv);
        void updateGameLoop(int val);
        void runGameLoop();
};

#endif
