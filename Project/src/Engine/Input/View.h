#ifndef _INPUT_VIEW_H
#define _INPUT_VIEW_H

#include "Model.h"

namespace Input {

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
