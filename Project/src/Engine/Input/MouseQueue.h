#ifndef _MOUSE_QUEUE_H
#define _MOUSE_QUEUE_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Queue.h"
#include "Events/MouseEvent.h"

namespace Input {

	class MouseQueue:
		public Queue< MouseEvent > {

	private:
		friend class Singleton< MouseQueue >;
		
	public:
		MouseQueue() {
			
		}

	};
}

#endif
