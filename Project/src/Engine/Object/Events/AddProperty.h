#ifndef _OBJECT_ADD_PROPERTY_H
#define _OBJECT_ADD_PROPERTY_H

#include "../../../Common/Base/Event.h"
#include "../../../Common/Types/Types.h"

namespace Object {

	template< typename T >
	class AddProperty:
	
		public Event< AddProperty< T > > {

	private:

		const StringID id;

	public:

		AddProperty( const StringID id ) :
			Event< AddProperty< T > >( 0 ), id{ id } {
		}
		const StringID get_id() const {
			return id;
		}
	};
}

#endif
