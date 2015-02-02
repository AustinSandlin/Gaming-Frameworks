#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H

#include "../../Common/Events/EventHandlerMap.h"

class GameController : public EventHandlerMap {
public:
	static GameController & GetInstance() {
		static GameController singleton;
		return singleton;
	}
private:
	GameController() {}
};

#endif
