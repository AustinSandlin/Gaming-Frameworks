#ifndef _SCHEDULER_CONTROLLER_H
#define _SCHEDULER_CONTROLLER_H

#include "../../Common/Base/Handler.h"
#include "../../Common/Base/Singleton.h"

namespace Scheduler {

	class Controller:
		
		public Singleton< Controller > {

	private:

		friend class Singleton< Controller >;
		Controller() {
		}
	};
}

#endif
