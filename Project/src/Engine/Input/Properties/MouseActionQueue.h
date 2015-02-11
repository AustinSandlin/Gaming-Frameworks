#ifndef _INPUT_MOUSE_ACTION_QUEUE_H
#define _INPUT_MOUSE_ACTION_QUEUE_H

#include "../../../Common/Base/Queue.h"

#include "../Events/MouseAction.h"

class MouseActionQueue:

	public Queue< MouseAction > {
};

#endif
