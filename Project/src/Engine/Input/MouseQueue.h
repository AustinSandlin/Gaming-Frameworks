#ifndef _MOUSE_QUEUE_H
#define _MOUSE_QUEUE_H

#include "../../Common/Base/Queue.h"
#include "Events/MouseEvent.h"

namespace Input {

	class MouseQueue:
		public Queue< MouseEvent > {

	private:
		
	public:
		MouseQueue() {
			
		}

	};
}

#endif
