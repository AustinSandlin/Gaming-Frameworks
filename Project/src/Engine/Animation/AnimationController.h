#ifndef _ANIMATION_CONTROLLER_H
#define _ANIMATION_CONTROLLER_H

#include "../../Common/Events/EventHandlerMap.h"

class AnimationController : public EventHandlerMap {
public:
	static AnimationController & GetInstance() {
		static AnimationController singleton;
		return singleton;
	}
private:
	AnimationController() {}
};

#endif
