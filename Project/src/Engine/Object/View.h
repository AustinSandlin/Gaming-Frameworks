#ifndef _OBJECT_VIEW_H
#define _OBJECT_VIEW_H

#include "Model.h"

namespace Object {

	class View :

		public Singleton< View > {

	private:

		friend class Singleton< View >;
		View() {
		}

	public:

	};
}

#endif
