#ifndef _INPUT_POP_ACTION_H
#define _INPUT_POP_ACTION_H

#include "../../../Common/Base/Event.h"

namespace Input {

	template< typename T >
	class PopAction:
	
		public Event< PopAction< T > > {

	private:

		const StringID id;

	public:
		PopAction( const StringID id ) :
			Event< PopAction< T > >( 0 ), id{ id } {
		}
		const StringID get_id() const {
			return id;
		}
	};
}

#endif
