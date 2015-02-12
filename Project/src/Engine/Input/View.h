#ifndef _INPUT_VIEW_H
#define _INPUT_VIEW_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"

#include "Properties/KeyboardActionQueue.h"
#include "Properties/MouseActionQueue.h"

namespace Input {

	class View:

		public Singleton< View > {

	private:

		friend class Singleton< View >;
		View() {
		}

	public:

		const Table< KeyboardActionQueue > & get_keyboard_action_queues() const;
		const Table< MouseActionQueue > & get_mouse_action_queues() const;
	};
}

#endif
