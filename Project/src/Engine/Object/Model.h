#ifndef _OBJECT_MODEL_H
#define _OBJECT_MODEL_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"

#include "Controller.h"
#include "View.h"

namespace Object {

	class Model:

		private Singleton< Model > {

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
