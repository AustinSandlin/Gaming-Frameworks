#ifndef _KEYBOARD_QUEUE_H
#define _KEYBOARD_QUEUE_H

#include "../../Common/Base/Queue.h"
#include "Events/KeyboardEvent.h"

namespace Input {

	class KeyboardQueue:
		public Queue< KeyboardEvent > {

	private:

	public:
		KeyboardQueue() {
			
		}
	};
}

#endif
