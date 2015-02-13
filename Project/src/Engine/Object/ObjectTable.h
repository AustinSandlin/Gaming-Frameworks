#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Event.h"

namespace Input {

	class ObjectTable : public Singleton< ObjectTable >{

	private:

		friend class Singleton< ObjectTable >;
		
		ObjectTable() {
		}

	public:

	};
}

#endif
