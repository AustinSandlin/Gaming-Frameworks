#ifndef _OBJECT_REMOVE_PROPERTIES_H
#define _OBJECT_REMOVE_PROPERTIES_H

#include "../../../Common/Base/Event.h"
#include "../../../Common/Types/String.h"

namespace Object {

	class RemoveProperties:

		public Event< RemoveProperties > {

	private:

		const StringID id;

	public:

		RemoveProperties( const StringID id ) :
			Event< RemoveProperties >( 0 ), id{ id } {
		}
		const StringID get_id() const {
			return id;
		}
	};
}

#endif
