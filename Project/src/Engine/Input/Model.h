#ifndef _INPUT_MODEL_H
#define _INPUT_MODEL_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"

#include "Properties/KeyboardActionQueue.h"
#include "Properties/MouseActionQueue.h"

#include "Controller.h"
#include "View.h"

namespace Input {

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
