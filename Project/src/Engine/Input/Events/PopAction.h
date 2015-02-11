#ifndef _INPUT_POP_ACTION_H
#define _INPUT_POP_ACTION_H

#include "../../../Common/Base/Event.h"

namespace Input {

	template< typename T >
	class PopQueue:
	
		public Event {

	private:

		StringID id;
		T action;

	public:
		PushQueue( const StringID id, const T & action ) :
			id{ id }, action{ action } {
		}
		const StringID get_id() {
			return id;
		}
		const T & get_action() {
			return action;
		}
	};
}

#endif
