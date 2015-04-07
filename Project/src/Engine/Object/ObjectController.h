#ifndef _OBJECT_CONTROLLER_H
#define _OBJECT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Types.h"
#include "../../Common/Base/Queue.h"
#include "../../Common/Resources/Strings.h"

#include "Objects/PlayerObject.h"
#include "Objects/AIObject.h"
#include "Objects/GameObject.h"
#include "Objects/BackgroundObject.h"
#include "Objects/HUDObject.h"

#include "../Audio/AudioController.h"
#include "../Render/RenderController.h"
#include "../../Common/Resources/Constants.h"

#include <stdlib.h>
#include <time.h>
#include <queue>
#include <cmath>

class ObjectController:
	
	public Singleton< ObjectController > {

	private:

		friend class Singleton< ObjectController >;
		static RenderController& render_controller;
		static AudioController& audio_controller;
		
		// Old tables
		Table< AIObject > ai_objects;
		Table< BackgroundObject > background_objects;
		Table< PlayerObject > player_objects;
		Table< GameObject > game_objects;

		Table< HUDObject > debug_objects;
		Table< HUDObject > hud_objects;


		Table< Object > players;
		Table< Object > backgrounds;
		Table< Object > solidwalls;
		Table< Object > breakablewalls;
		Table< Object > rusherenemies;
		Table< Object > shooterenemies;
		Table< Object > bullets;
		Table< Object > healthpickups;
		Table< Object > scorepickups;


		ObjectController() {
			srand(time(NULL));
		}


		bool checkCollision(const Object a, const Object b);
		bool checkCollisionQuadQuad(const Object a, const Object b);
		bool checkCollisionQuadCircle (const Object a, const Object b);
		bool checkCollisionCircleCircle(const Object a, const Object b);
		double distance(const double x1, const double y1, const double x2, const double y2);

		bool doesSquareCollide( int, int, int, int, int, int, int, int );

		bool canAIMove( const StringID id, Direction dir );
		bool canPlayerMove( const StringID id, Direction dir);
	
	public:

		void handlePlayerAction( const InputAction& action );

		void registerObjectTexture( const StringID& id, const String );

		void addObject(const StringID& id, Object object);
		void removeObject(const StringID& id);

		void registerAIObject( const StringID& id, AIObject ai );
		void registerBackgroundObject( const StringID& id, BackgroundObject bo );
		void registerGameObject( const StringID& id, GameObject go );
		void registerPlayerObject( const StringID& id, PlayerObject po );
		void registerHUDObject( const StringID& id, HUDObject ho );
		void registerDebugObject( const StringID& id, HUDObject ho );
		void assignDebugValue( const StringID& id, int* ptr );

		void updateEntitys();
		void resetEntitys();
		void drawObjects();
};

#endif
