#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H

#if defined(_WIN32) || defined(WIN32)   
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Types/Types.h"

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
    
        Table< InputAction > input_action_table;

        GameController() {
        }

        static void keyboardInputCallback(unsigned char key, int x, int y) {
            input_controller.queueKeyboardEvent(key, x, y);
        }

        static void mouseInputCallback(int button, int state, int x, int y) {
            input_controller.queueMouseEvent(button, state, x, y);
        }

        static void renderDisplayCallback() {
            render_controller.renderScreen();
        }

        static void updateTimerCallback(int val) {
            game_controller.updateGameLoop(val);
        }


    public:
        void handleInputEvent( const StringID& id );
        void registerInputAction( const StringID& id, const InputAction action );

        void setupGameLoop(int argc, char **argv);
        void updateGameLoop(int val);
        void runGameLoop();
};

#endif
