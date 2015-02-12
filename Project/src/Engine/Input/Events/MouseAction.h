#ifndef _INPUT_MOUSE_ACTION_H
#define _INPUT_MOUSE_ACTION_H

#include "../../../Common/Base/Event.h"

namespace Input {
	
	class MouseAction:

		public Event< MouseAction > {

	private:
		int button;
		int state;
		int x;
		int y;
		
	public:
		MouseAction( int button, int state, int x, int y ) :
			Event< MouseAction >( 0 ), button{ button }, state{ state }, x{ x }, y{ y } {
		}
		int get_button() {
			return button;
		}
		int get_state() {
			return state;
		}
		int get_x() {
			return x;
		}
		int get_y() {
			return y;
		}
	};
}

#endif
