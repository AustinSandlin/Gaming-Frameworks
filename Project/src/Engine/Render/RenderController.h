#ifndef _RENDER_CONTROLLER_H
#define _RENDER_CONTROLLER_H

#include "../../Common/Events/EventHandlerMap.h"

class RenderController : public EventHandlerMap {
public:
	static RenderController & GetInstance() {
		static RenderController singleton;
		return singleton;
	}
private:
	RenderController() {}
};

#endif
