#ifndef _OBJECT_CONTROLLER_H
#define _OBJECT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Types/Types.h"
#include "../../Common/Resources/Strings.h"

#include "GameObject.h"
#include "PlayerObject.h"

static Strings& ObjectStrController = Strings::instance();

class ObjectController:
	
	public Singleton< ObjectController > {

	private:

		friend class Singleton< ObjectController >;
		PlayerObject player;
		Table< GameObject > game_objects;

		ObjectController() : 
			player( ObjectStrController.intern("Player1"), 0, 0 ) {
		}

	public:

		void handlePlayerAction( const InputAction& action );
		void registerGameObject( const StringID& id, GameObject go );

		bool canMoveUpPlayer();
		bool canMoveDownPlayer();
		bool canMoveLeftPlayer();
		bool canMoveRightPlayer();
};

#endif
