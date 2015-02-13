#ifndef _OBJECT_CONTROLLER_H
#define _OBJECT_CONTROLLER_H

#include "../../Common/Base/Handler.h"
#include "../../Common/Base/Singleton.h"

#include "Events/RemoveProperties.h"

namespace Object {

	class ObjectController:
		
		public Singleton< ObjectController > {

	private:

		friend class Singleton< ObjectController >;

		ObjectController() {
		}

	public:

		void handle( const Event& event );
	};
}

#endif
