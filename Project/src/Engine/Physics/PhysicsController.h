#ifndef _PHYSICS_CONTROLLER_H
#define _PHYSICS_CONTROLLER_H

#include "../../Common/Events/EventHandlerMap.h"

class PhysicsController : public EventHandlerMap {
public:
	static PhysicsController & GetInstance() {
		static PhysicsController singleton;
		return singleton;
	}
private:
	PhysicsController() {}
};

#endif
