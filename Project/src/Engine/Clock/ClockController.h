#ifndef _CLOCK_CONTROLLER_H
#define _CLOCK_CONTROLLER_H

#include "../../Common/Events/EventHandlerMap.h"

class ClockController : public EventHandlerMap {
public:
	static ClockController & GetInstance() {
		static ClockController singleton;
		return singleton;
	}
private:
	ClockController() {}
};

#endif
