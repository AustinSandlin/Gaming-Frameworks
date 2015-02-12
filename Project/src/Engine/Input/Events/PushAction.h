#ifndef _INPUT_PUSH_ACTION_H
#define _INPUT_PUSH_ACTION_H

#include "../../../Common/Base/Event.h"

namespace Input {

	template< typename T >
	class PushAction:
	
		public Event< PushAction< T > > {

	private:

		const T action;

	public:
		
		PushAction( const T & action ) :
			Event< PushAction< T > >( 0 ), action{ action } {
		}
		const T & get_action() const {
			return action;
		}
	};
}

#endif
