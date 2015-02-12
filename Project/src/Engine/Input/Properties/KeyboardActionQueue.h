#ifndef _INPUT_KEYBOARD_ACTION_QUEUE_H
#define _INPUT_KEYBOARD_ACTION_QUEUE_H

#include "../../../Common/Base/Queue.h"

#include "../Events/KeyboardAction.h"

namespace Input {
	
	class KeyboardActionQueue:

		public Queue< KeyboardAction > {
	};
}

#endif