#ifndef _OBJECT_CONTROLLER_H
#define _OBJECT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Types.h"
#include "../../Common/Base/Queue.h"
#include "../../Common/Resources/Strings.h"

#include "Objects/GameObject.h"
#include "Objects/PlayerObject.h"
#include "Objects/BackgroundObject.h"
#include "Objects/HUDObject.h"

#include <queue>

static Strings& ObjectStrController = Strings::instance();

class ObjectController:
	
	public Singleton< ObjectController > {

	private:

		friend class Singleton< ObjectController >;
		Table< BackgroundObject > background_objects;
		Table< PlayerObject > player_objects;
		Table< GameObject > game_objects;

		Table< HUDObject > debug_objects;
		Table< HUDObject > hud_objects;

		ObjectController() {
		}

		bool canMoveUpPlayer( const StringID id );
		bool canMoveDownPlayer( const StringID id );
		bool canMoveLeftPlayer( const StringID id );
		bool canMoveRightPlayer( const StringID id );
	
	public:

		void handlePlayerAction( const InputAction& action );

		void registerBackgroundObject( const StringID& id, BackgroundObject bo );
		void registerGameObject( const StringID& id, GameObject go );
		void registerPlayerObject( const StringID& id, PlayerObject po );

		void registerHUDObject( const StringID& id, HUDObject ho );
		void registerDebugObject( const StringID& id, HUDObject ho );
		void assignDebugValue( const StringID& id, int* ptr );

		int getObjectLocationX( const StringID );
		int getObjectLocationY( const StringID );

		std::queue<StringID> queueObjects();
		std::queue<HUDObject> queueDebugs();
};

#endif
