#ifndef _SCHEDULER_MODEL_H
#define _SCHEDULER_MODEL_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Queue.h"
#include "../../Common/Base/Table.h"

#include "Properties/KeyboardActionQueue.h"
#include "Properties/MouseActionQueue.h"

#include "InputController.h"
#include "InputView.h"

namespace Scheduler {

	class Model:

		private Singleton< Model >,

		private Table< KeyboardActionQueue >,
		private Table< MouseActionQueue > {

	private:
		
		friend class Singleton< Model >;
		
		friend class Controller;
		friend class View;

		Model() {
		}

	public:

		template< typename T >
		Table< T > & get_table() {
			return *this;
		}
	};
}

#endif
