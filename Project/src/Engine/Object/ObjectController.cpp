#include "ObjectController.h"

Strings & ObjectController::strings = Strings::instance();
AudioController & ObjectController::audio_controller = AudioController::instance();
RenderController & ObjectController::render_controller = RenderController::instance();
TriggerController & ObjectController::trigger_controller = TriggerController::instance();

void ObjectController::handlePlayerAction( const InputAction& action ) {

    TableIterator<PlayerObject> it = player_objects.begin();
    while(it != player_objects.end()) {
        switch(action) {
            case MOVE_UP:
                if(canPlayerMove( it.getValue().getID(), UP)) {
                    it.getValue().setState(MOVING);
                    it.getValue().setDir(UP);
                    it.getValue().move();
                }
                else {
                    audio_controller.playSound( "collision" );
                }
                break;
            case MOVE_DOWN:
                if(canPlayerMove( it.getValue().getID(), DOWN)) {
                    it.getValue().setState(MOVING);
                    it.getValue().setDir(DOWN);
                    it.getValue().move();
                }
                else {
                    audio_controller.playSound( "collision" );
                }
                break;
            case MOVE_LEFT:
                if(canPlayerMove( it.getValue().getID(), LEFT)) {
                    it.getValue().setState(MOVING);
                    it.getValue().setDir(LEFT);
                    it.getValue().move();
                }
                else {
                    audio_controller.playSound( "collision" );
                }
                break;
            case MOVE_RIGHT:
                if(canPlayerMove( it.getValue().getID(), RIGHT)) {
                    it.getValue().setState(MOVING);
                    it.getValue().setDir(RIGHT);
                    it.getValue().move();
                }
                else {
                    audio_controller.playSound( "collision" );
                }
                break;
            default:
                break;
        }
        ++it;
    }
}

void ObjectController::registerObjectTexture( const StringID& id, const String path ) {
    GLuint textureID = render_controller.loadBMP(path.c_str());

    if(background_objects.has(id)) {
        background_objects.get(id).getValue().addTexture(textureID);
    }
    else if(game_objects.has(id)) {
        game_objects.get(id).getValue().addTexture(textureID);
    }
    else if(ai_objects.has(id)) {
        ai_objects.get(id).getValue().addTexture(textureID);
    }
    else if(player_objects.has(id)) {
        player_objects.get(id).getValue().addTexture(textureID);
    }
    else if(hud_objects.has(id)) {
        hud_objects.get(id).getValue().addTexture(textureID);
    }
}

void ObjectController::registerAIObject( const StringID& id, AIObject ai ) {
    ai_objects.add( id, ai );
}

void ObjectController::registerBackgroundObject( const StringID& id, BackgroundObject bo ) {
    background_objects.add( id, bo );
}

void ObjectController::registerPlayerObject( const StringID& id, PlayerObject po ) {
    int size = 0;
    TableIterator<PlayerObject> it1 = player_objects.begin();
    while(it1 != player_objects.end()) {
        ++size;
        ++it1;
    }

    if(size < 1) {
        player_objects.add( id, po );
    }
}

void ObjectController::registerGameObject( const StringID& id, GameObject go ) {
    game_objects.add( id, go );
}

void ObjectController::registerHUDObject( const StringID& id, HUDObject ho ) {
    hud_objects.add( id, ho );
}

void ObjectController::assignValue( const StringID& id, String var ) {
    if(hud_objects.has(id)) {
        hud_objects.get(id).getValue().updateValue(var);
    }
}

void ObjectController::removeObject(const StringID& id) {
    // Removing background objects:
    if(ai_objects.has(id)) {
        ai_objects.remove(id);
    }
    if(background_objects.has(id)) {
        background_objects.remove(id);
    }
    if(player_objects.has(id)) {
        player_objects.remove(id);
    }
    if(game_objects.has(id)) {
        game_objects.remove(id);
    }
    if(hud_objects.has(id)) {
        hud_objects.remove(id);
    }
}

bool ObjectController::doesSquareCollide( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 ) {
    bool coll = false;

    if((y1 < (y3+y4)) && ((y1+y2) > y3) && ((x1+x2) > x3) && (x1 < (x3+x4))) {
        coll = true;
    }

    return coll;
}

bool ObjectController::canAIMove( const StringID id, Direction dir ) {
    bool coll = false;

    AIObject ai = ai_objects.get(id).getValue();
    int testX = ai.getX();
    int testY = ai.getY();

    //Determine the new entity state and change the test directions.
    switch(dir) {
        case UP: testY += ai.getVelocity(); break;
        case DOWN: testY -= ai.getVelocity(); break;
        case LEFT: testX -= ai.getVelocity(); break;
        case RIGHT: testX += ai.getVelocity(); break;
        default: break;
    }

    TableIterator<GameObject> it1 = game_objects.begin();
    while(it1 != game_objects.end() && !coll) {
        if(it1.getValue().getCollidable() &&
           doesSquareCollide(testX, testY, ai.getWidth(), ai.getHeight(),
                             it1.getValue().getX(), it1.getValue().getY(),
                             it1.getValue().getWidth(), it1.getValue().getHeight())) {
            coll = true;

            // Update triggers if a collision occured
            String first = strings.lookup( id );
            String second = strings.lookup( it1.getValue().getID() );
            trigger_controller.updateCollisionTriggers( first, second );
        }
        ++it1;
    }
    TableIterator<PlayerObject> it2 = player_objects.begin();
    while(it2 != player_objects.end() && !coll) {
        if(doesSquareCollide(testX, testY, ai.getWidth(), ai.getHeight(),
                             it2.getValue().getX(), it2.getValue().getY(),
                             it2.getValue().getWidth(), it2.getValue().getHeight())) {
            coll = true;

            // Update triggers if a collision occured
            String first = strings.lookup( id );
            String second = strings.lookup( it2.getValue().getID() );
            trigger_controller.updateCollisionTriggers( first, second );
        }
        ++it2;
    }

    return !coll;
}

bool ObjectController::canPlayerMove( const StringID id, Direction dir ) {
    bool coll = false;

    PlayerObject player = player_objects.get(id).getValue();
    int testX = player.getX();
    int testY = player.getY();

    //Determine the new entity state and change the test directions.
    switch(dir) {
        case UP: testY += player.getVelocity(); break;
        case DOWN: testY -= player.getVelocity(); break;
        case LEFT: testX -= player.getVelocity(); break;
        case RIGHT: testX += player.getVelocity(); break;
        default: break;
    }

    TableIterator<GameObject> it1 = game_objects.begin();
    while(it1 != game_objects.end() && !coll) {
        if(it1.getValue().getCollidable() &&
           doesSquareCollide(testX, testY, player.getWidth(), player.getHeight(),
                             it1.getValue().getX(), it1.getValue().getY(),
                             it1.getValue().getWidth(), it1.getValue().getHeight())) {
            coll = true;

            // Update triggers if a collision occured
            String first = strings.lookup( id );
            String second = strings.lookup( it1.getValue().getID() );
            trigger_controller.updateCollisionTriggers( first, second );
        }
        ++it1;
    }
    TableIterator<AIObject> it2 = ai_objects.begin();
    while(it2 != ai_objects.end() && !coll) {
        if(doesSquareCollide(testX, testY, player.getWidth(), player.getHeight(),
                             it2.getValue().getX(), it2.getValue().getY(),
                             it2.getValue().getWidth(), it2.getValue().getHeight())) {
            coll = true;

            // Update triggers if a collision occured
            String first = strings.lookup( id );
            String second = strings.lookup( it2.getValue().getID() );
            trigger_controller.updateCollisionTriggers( first, second );
        }
        ++it2;
    }

    return !coll;
    // return true;
}

void ObjectController::updateEntitys() {
    TableIterator<AIObject> it1 = ai_objects.begin();
    while(it1 != ai_objects.end()) {
        StringID id = it1.getID();
        if(it1.getValue().getType() == WANDER) {
            int x = rand()%10;
            if(x < 5) {
                it1.getValue().setState(IDLE);
            }
            else if(x > 8) {
                it1.getValue().setState(MOVING);
            }

            if(it1.getValue().getState() == MOVING) {
                x = rand()%40;
                switch(x) {
                    case 0: it1.getValue().setDir(UP); break;
                    case 10: it1.getValue().setDir(DOWN); break;
                    case 20: it1.getValue().setDir(LEFT); break;
                    case 30: it1.getValue().setDir(RIGHT); break;
                    default: break;
                }
                if(canAIMove(it1.getValue().getID(), it1.getValue().getDir())) {
                    it1.getValue().move();
                }
            }
        }
        else if(it1.getValue().getType() == STILL) {
        }
        else if(it1.getValue().getType() == RUSHER) {
            TableIterator<PlayerObject> it2 = player_objects.begin();
            int p_x = it2.getValue().getX();
            int p_y = it2.getValue().getY();
            int a_x = it1.getValue().getX();
            int a_y = it1.getValue().getY();

            if((((a_x-p_x)*(a_x-p_x))+((a_y-p_y)*(a_y-p_y))) < (AI_AGGRO_RADIUS*AI_AGGRO_RADIUS)) {
                if(p_x == a_x && p_y < a_y) {
                    it1.getValue().setDir(DOWN);
                }
                else if(p_x == a_x && p_y > a_y) {
                    it1.getValue().setDir(UP);
                }
                else if(p_y == a_y && p_x < a_x) {
                    it1.getValue().setDir(LEFT);
                }
                else if(p_y == a_y && p_x > a_x) {
                    it1.getValue().setDir(RIGHT);
                }
                else if(p_x < a_x && p_y < a_y) {
                    if(it1.getValue().getDir() == DOWN) {
                        it1.getValue().setDir(LEFT);
                    }
                    else {
                        it1.getValue().setDir(DOWN);
                    }
                }
                else if(p_x > a_x && p_y < a_y) {
                    if(it1.getValue().getDir() == DOWN) {
                        it1.getValue().setDir(RIGHT);
                    }
                    else {
                        it1.getValue().setDir(DOWN);
                    }
                }
                else if(p_x < a_x && p_y > a_y) {
                    if(it1.getValue().getDir() == UP) {
                        it1.getValue().setDir(LEFT);
                    }
                    else {
                        it1.getValue().setDir(UP);
                    }
                }
                else if(p_x > a_x && p_y > a_y) {
                    if(it1.getValue().getDir() == UP) {
                        it1.getValue().setDir(RIGHT);
                    }
                    else {
                        it1.getValue().setDir(UP);
                    }
                }
                if(canAIMove(it1.getValue().getID(), it1.getValue().getDir())) {
                    it1.getValue().move();
                }
            }
        }

        if(!ai_objects.has(id)) {
            it1 = ai_objects.begin();
        }
        else {
            ++it1;
        }
    }
}

void ObjectController::drawObjects() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int x = 0;
    int y = 0;
    int count = 0;

    // Centering camera on the players:
    TableIterator<PlayerObject> it = player_objects.begin();
    while(it != player_objects.end()) {
        x += it.getValue().getX();
        y += it.getValue().getY();
        ++count;
        ++it;
    }

    x /= count;
    y /= count;

    x = (ORTHO_RIGHT / 2) - x;
    y = (ORTHO_TOP / 2) - y;

    glTranslatef(x, y, 0);

    // Drawing background objects:
    TableIterator<BackgroundObject> it1 = background_objects.begin();
    while(it1 != background_objects.end()) {
        it1.getValue().draw();
        ++it1;
    }

    // Drawing game objects:
    TableIterator<GameObject> it2 = game_objects.begin();
    while(it2 != game_objects.end()) {
        it2.getValue().draw();
        ++it2;
    }

    // Drawing AI objects:
    TableIterator<AIObject> it3 = ai_objects.begin();
    while(it3 != ai_objects.end()) {
        it3.getValue().draw();
        ++it3;
    }

    // Drawing player objects:
    TableIterator<PlayerObject> it4 = player_objects.begin();
    while(it4 != player_objects.end()) {
        it4.getValue().draw();
        ++it4;
    }
    
    // stop centering on player do the hud follows the screen.
    glTranslatef(-x, -y, 0);
    TableIterator<HUDObject> it5 = hud_objects.begin();
    while(it5 != hud_objects.end()) {
        it5.getValue().draw();
        ++it5;
    }

    glutSwapBuffers();
}
