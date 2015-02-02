#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "../../Common/Events/EventHandlerMap.h"

class InputController : public EventHandlerMap {
public:
	static InputController & GetInstance() {
		static InputController singleton;
		return singleton;
	}
private:
	InputController();
};

#endif
