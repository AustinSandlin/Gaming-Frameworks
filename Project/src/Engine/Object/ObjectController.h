#ifndef _OBJECT_CONTROLLER_H
#define _OBJECT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Types.h"
#include "../../Common/Resources/Strings.h"

#include "Objects/GameObject.h"
#include "Objects/PlayerObject.h"

static Strings& ObjectStrController = Strings::instance();

class ObjectController:
	
	public Singleton< ObjectController > {

	private:

		friend class Singleton< ObjectController >;
		Table< PlayerObject > player_objects;
		Table< GameObject > game_objects;

		ObjectController() {
		}

		bool canMoveUpPlayer( const StringID id );
		bool canMoveDownPlayer( const StringID id );
		bool canMoveLeftPlayer( const StringID id );
		bool canMoveRightPlayer( const StringID id );
	
	public:

		void handlePlayerAction( const InputAction& action );

		void registerGameObject( const StringID& id, GameObject go );
		void registerPlayerObject( const StringID& id, PlayerObject po );
};

#endif
