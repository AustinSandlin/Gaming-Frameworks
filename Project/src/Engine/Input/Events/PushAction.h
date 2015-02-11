#ifndef _INPUT_PUSH_ACTION_H
#define _INPUT_PUSH_ACTION_H

#include "../../../Common/Base/Event.h"

namespace Input {

	template< typename T >
	class PushAction:
	
		public Event {

	private:

		T action;

	public:
		PushAction( const T & action ) :
			value{ value } {
		}
		const T & get_action() {
			return action;
		}
	};
}

#endif
