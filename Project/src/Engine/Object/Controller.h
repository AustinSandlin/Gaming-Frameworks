#ifndef _OBJECT_CONTROLLER_H
#define _OBJECT_CONTROLLER_H

#include "../../Common/Base/Handler.h"
#include "../../Common/Base/Singleton.h"

#include "Events/RemoveProperties.h"

namespace Object {

	class Controller:
		
		public Singleton< Controller >,
		public Handler< RemoveProperties > {

	private:

		friend class Singleton< Controller >;
		Controller() {
		}

	public:

		void handle( const RemoveProperties & event );
	};
}

#endif
