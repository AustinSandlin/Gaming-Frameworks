#ifndef _INPUT_KEYBOARD_ACTION_QUEUE_H
#define _INPUT_KEYBOARD_ACTION_QUEUE_H

#include "../../../Common/Base/Queue.h"

#include "../Properties/KeyboardAction.h"

class KeyboardActionQueue:

	public Queue< KeyboardAction > {
};

#endif
