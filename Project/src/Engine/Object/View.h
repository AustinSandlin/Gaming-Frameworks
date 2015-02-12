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

		template< typename T >
		const Table< T > & get_table() const {
			static auto & model = Model::instance();
			return model.get_table< T >();
		}
	};
}

#endif
