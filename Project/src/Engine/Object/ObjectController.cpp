#include "ObjectController.h"

RenderController& ObjectController::render_controller = RenderController::instance();
AudioController& ObjectController::audio_controller = AudioController::instance();


void ObjectController::addObject(const StringID& id, Object object) {
    // The object is added to the same table as all other objects of its type.
    ObjectType type = object.getType();

    switch(type) {
        case PLAYER:
            int size = 0;
            TableIterator<Object> it1 = players.begin();
            while(it1 != players.end()) {
                ++size;
                ++it1;
            }

            if(size < 1) {
                players.add( id, object );
            }
            break;
        case BACKGROUND:
            backgrounds.add(id, object);
            break;
        case SOLIDWALL:
            solidwalls.add(id, object);
            break;
        case BREAKABLEWALL:
            breakablewalls.add(id, object);
            break;
        case RUSHERENEMY:
            rusherenemies.add(id, object);
            break;
        case SHOOTERENEMY:
            shooterenemies.add(id, object);
            break;
        case BULLET:
            bullets.add(id, object);
            break;
        case HEALTHPICKUP:
            healthpickups.add(id, object);
            break;
        case SCOREPICKUP:
            scorepickups.add(id, object);
            break;
        default:
            break;
    }
}


void ObjectController::removeObject(const StringID& id) {
    // The object is removed from the table it belongs to.
    if (players.has(id)) {
        players.remove(id);
    }
    else if (backgrounds.has(id)) {
        backgrounds.remove(id);
    }
    else if (solidwalls.has(id)) {
        solidwalls.remove(id);
    }
    else if (breakablewalls.has(id)) {
        breakablewalls.remove(id);
    }
    else if (rusherenemies.has(id)) {
        rusherenemies.remove(id);
    }
    else if (shooterenemies.has(id)) {
        shooterenemies.remove(id);
    }
    else if (bullets.has(id)) {
        bullets.remove(id);
    }
    else if (healthpickups.has(id)) {
        healthpickups.remove(id);
    }
    else if (scorepickups.has(id)) {
        scorepickups.remove(id);
    }
}


bool ObjectController::checkCollision(const Object a, const Object b) {
    // Check collision if A and B are both quads:
    if (a.isQuad() && b.isQuad()) {
        checkCollisionQuadQuad(a, b);
    }
    // Check collision if A and B are both circles:
    else if (!a.isQuad() && !b.isQuad()) {
        checkCollisionCircleCircle(a, b);
    }
    // Check collision if A is a quad and B is a circle:
    else if (a.isQuad() && !b.isQuad()) {
        checkCollisionQuadCircle(a, b);
    }
    // Check collision if A is a circle and B is a quad:
    else {
        checkCollisionQuadCircle(b, a);
    }
}



/*      Unfinished.

bool ObjectController::checkCollisionCircleCircle(const Object a, const Object b) {
    // The two objects have collided if the distance between their centers is less than
    // the sum of their radii.
    bool collision = false;

    double distance = distance(a.getX(), a.getY(), b.getX(), b.getY());

    if (distance <= (a.getRadius() + b.getRadius())) {
        collision = true;
    }

    return collision;
}


bool ObjectController::checkCollisionQuadQuad(const Object a, const Object b) {

}


bool ObjectController::checkCollisionQuadCircle(const Object a, const Object b) {
    bool collision = false;

    // The location of the points of the quad based on its center point, its
    // angle of rotation, and its width and height. The last is a duplicate
    // of the first so they can be considered in pairs.
    double verticesX[5];
    double verticesY[5];

    // The location, width, height and rotation of the quad and radius of the circle:
    double aX = a.getX();
    double aY = a.getY();
    double bX = b.getX();
    double bY = b.getY();
    double width = a.getWidth();
    double height = a.getHeight();
    double angle = a.getRotation() * PI / 180;
    double radius = b.getRadius();

    // Bottom left (at 0 degrees):
    verticesX[0] = aX - (cos(angle) * (width / 2))  + (sin(angle) * (height / 2));
    verticesY[0] = aY - (cos(angle) * (height / 2)) - (sin(angle) * (width / 2));

    // Bottom right (at 0 degrees):
    verticesX[1] = aX + (cos(angle) * (width / 2))  + (sin(angle) * (height / 2));
    verticesY[1] = aY - (cos(angle) * (height / 2)) + (sin(angle) * (width / 2));

    // Top right (at 0 degrees):
    verticesX[2] = aX + (cos(angle) * (width / 2))  - (sin(angle) * (height / 2));
    verticesY[2] = aY + (cos(angle) * (height / 2)) + (sin(angle) * (width / 2));

    // Top left (at 0 degrees):
    verticesX[3] = aX - (cos(angle) * (width / 2))  - (sin(angle) * (height / 2));
    verticesY[3] = aY + (cos(angle) * (height / 2)) - (sin(angle) * (width / 2));

    // Bottom left again:
    verticesX[4] = verticesX[0];
    verticesY[4] = verticesY[0];



    return collision;
}
*/



double ObjectController::distance(const double x1, const double y1, const double x2, const double y2) {
    // Simple distance function for two points.
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return distance;
}


void ObjectController::handlePlayerAction( const InputAction& action ) {                // MERGE with collision/logic functions

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

    if (players.has(id)) {
        players.get(id).getValue().addTexture(textureID);
    }
    else if (backgrounds.has(id)) {
        backgrounds.get(id).getValue().addTexture(textureID);
    }
    else if (solidwalls.has(id)) {
        solidwalls.get(id).getValue().addTexture(textureID);
    }
    else if (breakablewalls.has(id)) {
        breakablewalls.get(id).getValue().addTexture(textureID);
    }
    else if (rusherenemies.has(id)) {
        rusherenemies.get(id).getValue().addTexture(textureID);
    }
    else if (shooterenemies.has(id)) {
        shooterenemies.get(id).getValue().addTexture(textureID);
    }
    else if (bullets.has(id)) {
        bullets.get(id).getValue().addTexture(textureID);
    }
    else if (healthpickups.has(id)) {
        healthpickups.get(id).getValue().addTexture(textureID);
    }
    else if (scorepickups.has(id)) {
        scorepickups.get(id).getValue().addTexture(textureID);
    }



    /*          // Old
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
    }*/
}

void ObjectController::registerAIObject( const StringID& id, AIObject ai ) {                            // OLD
    ai_objects.add( id, ai );
}

void ObjectController::registerBackgroundObject( const StringID& id, BackgroundObject bo ) {            // OLD
    background_objects.add( id, bo );
}

void ObjectController::registerPlayerObject( const StringID& id, PlayerObject po ) {                    // OLD
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

void ObjectController::registerGameObject( const StringID& id, GameObject go ) {                        // OLD
    game_objects.add( id, go );
}

void ObjectController::registerHUDObject( const StringID& id, HUDObject ho ) {                          // OLD
    hud_objects.add( id, ho );
}

void ObjectController::registerDebugObject( const StringID& id, HUDObject ho ) {                        // OLD
    debug_objects.add( id, ho );
}

void ObjectController::assignDebugValue( const StringID& id, int* ptr ) {                               // OLD
    if(debug_objects.has(id)) {
        debug_objects.get(id).getValue().updateValue(ptr);
    }
}

bool ObjectController::doesSquareCollide( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 ) {    // OLD
    bool coll = false;

    if((y1 < (y3+y4)) && ((y1+y2) > y3) && ((x1+x2) > x3) && (x1 < (x3+x4))) {
        coll = true;
    }

    return coll;
}

bool ObjectController::canAIMove( const StringID id, Direction dir ) {                        // MERGE with collision/logic functions
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
        }
        ++it1;
    }
    TableIterator<PlayerObject> it2 = player_objects.begin();
    while(it2 != player_objects.end() && !coll) {
        if(doesSquareCollide(testX, testY, ai.getWidth(), ai.getHeight(),
                             it2.getValue().getX(), it2.getValue().getY(),
                             it2.getValue().getWidth(), it2.getValue().getHeight())) {
            coll = true;
        }
        ++it2;
    }

    return !coll;
}

bool ObjectController::canPlayerMove( const StringID id, Direction dir ) {                  // MERGE with collision/logic functions
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
        }
        ++it1;
    }
    TableIterator<AIObject> it2 = ai_objects.begin();
    while(it2 != ai_objects.end() && !coll) {
        if(doesSquareCollide(testX, testY, player.getWidth(), player.getHeight(),
                             it2.getValue().getX(), it2.getValue().getY(),
                             it2.getValue().getWidth(), it2.getValue().getHeight())) {
            coll = true;
        }
        ++it2;
    }

    return !coll;
}

void ObjectController::updateEntitys() {                                            // MERGE with collision/logic functions
    TableIterator<AIObject> it1 = ai_objects.begin();
    while(it1 != ai_objects.end()) {
        if(it1.getValue().getType() == WANDER) {
            int x = rand()%100;
            if(x == 0) {
                it1.getValue().setState(IDLE);
            }
            else if(x > 4) {
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
        ++it1;
    }



    // TableIterator<PlayerObject> it2 = player_objects.begin();
    // while(it2 != player_objects.end()) {
    //     if(it2.getValue().getState() == MOVING) {
    //         it2.getValue().move();
    //         it2.getValue().setState(IDLE);
    //     }
    //     ++it2;
    // }
}

void ObjectController::drawObjects() {                                      // CHANGE
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int x = 0;
    int y = 0;
    int count = 0;

    // Centering camera on the players:
    TableIterator<Object> it = players.begin();
    while(it != players.end()) {
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
    it = backgrounds.begin();
    while(it != backgrounds.end()) {
        it.getValue().draw();
        ++it;
    } 

    // Drawing bullet objects:
    it = bullets.begin();
    while(it != bullets.end()) {
        it.getValue().draw();
        ++it;
    }

    // Drawing health pickup objects:
    it = healthpickups.begin();
    while(it != healthpickups.end()) {
        it.getValue().draw();
        ++it;
    } 

    // Drawing score pickup objects:
    it = scorepickups.begin();
    while(it != scorepickups.end()) {
        it.getValue().draw();
        ++it;
    }

    // Drawing rusher enemy objects:
    it = rusherenemies.begin();
    while(it != rusherenemies.end()) {
        it.getValue().draw();
        ++it;
    }

    // Drawing shooter enemy objects:
    it = shooterenemies.begin();
    while(it != shooterenemies.end()) {
        it.getValue().draw();
        ++it;
    } 

    // Drawing breakable wall objects:
    it = breakablewalls.begin();
    while(it != breakablewalls.end()) {
        it.getValue().draw();
        ++it;
    }

    // Drawing solid wall objects:
    it = solidwalls.begin();
    while(it != solidwalls.end()) {
        it.getValue().draw();
        ++it;
    }

    // Drawing player objects:
    it = players.begin();
    while(it != players.end()) {
        it.getValue().draw();
        ++it;
    } 




    /*
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

    // Drawing HUD objects:
    TableIterator<HUDObject> it5 = hud_objects.begin();
    while(it5 != hud_objects.end()) {
        it5.getValue().draw();
        ++it5;
    }

    // Drawing debug objects:
    TableIterator<HUDObject> it6 = debug_objects.begin();
    while(it6 != debug_objects.end()) {
        it6.getValue().draw();
        ++it6;
    }*/

    glutSwapBuffers();
}
