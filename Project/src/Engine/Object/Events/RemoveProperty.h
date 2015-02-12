#ifndef _OBJECT_REMOVE_PROPERTY_H
#define _OBJECT_REMOVE_PROPERTY_H

#include "../../../Common/Base/Event.h"
#include "../../../Common/Types/String.h"

namespace Object {

	template< typename T >
	class RemoveProperty:

		public Event< RemoveProperty< T > > {

	private:

		const StringID id;

	public:

		RemoveProperty( const StringID id ) :
			Event< RemoveProperty< T > >( 0 ), id{ id } {
		}
		const StringID & get_id() const {
			return id;
		}
	};
}

#endif
