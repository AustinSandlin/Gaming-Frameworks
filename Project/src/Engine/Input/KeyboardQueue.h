#ifndef _KEYBOARD_QUEUE_H
#define _KEYBOARD_QUEUE_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Queue.h"
#include "Events/KeyboardEvent.h"

namespace Input {

	class KeyboardQueue:
		public Queue< KeyboardEvent > {

	private:
		friend class Singleton< KeyboardQueue >;

	public:
		KeyboardQueue() {
			
		}
	};
}

#endif
