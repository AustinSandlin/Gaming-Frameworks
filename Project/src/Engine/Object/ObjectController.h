#ifndef _OBJECT_CONTROLLER_H
#define _OBJECT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Types.h"
#include "../../Common/Base/Queue.h"
#include "../../Common/Resources/Constants.h"
#include "../../Common/Resources/Strings.h"

#include "Objects/PlayerObject.h"
#include "Objects/AIObject.h"
#include "Objects/GameObject.h"
#include "Objects/BackgroundObject.h"
#include "Objects/HUDObject.h"

#include "../Audio/AudioController.h"
#include "../Render/RenderController.h"
#include "../../Common/Resources/Constants.h"
#include "../Trigger/TriggerController.h"

#include <stdlib.h>
#include <time.h>
#include <queue>

class ObjectController:
	
	public Singleton< ObjectController > {

	private:

		friend class Singleton< ObjectController >;

		static Strings & strings;
		static AudioController & audio_controller;
		static RenderController & render_controller;
		static TriggerController & trigger_controller;
		
		Table< AIObject > ai_objects;
		Table< BackgroundObject > background_objects;
		Table< PlayerObject > player_objects;
		Table< GameObject > game_objects;
		Table< HUDObject > hud_objects;

		ObjectController() {
			srand(time(NULL));
		}

		bool doesSquareCollide( int, int, int, int, int, int, int, int );

		bool canAIMove( const StringID id, Direction dir );
		bool canPlayerMove( const StringID id, Direction dir);
	
	public:

		void handlePlayerAction( const InputAction& action );
		void registerObjectTexture( const StringID& id, const String );

		void registerAIObject( const StringID& id, AIObject ai );
		void registerBackgroundObject( const StringID& id, BackgroundObject bo );
		void registerGameObject( const StringID& id, GameObject go );
		void registerPlayerObject( const StringID& id, PlayerObject po );

		void registerHUDObject( const StringID& id, HUDObject ho );
		void assignValue( const StringID& id, String var );

		void removeObject(const StringID& id);

		void updateEntitys();
		void resetEntitys();
		void drawObjects();
};

#endif
