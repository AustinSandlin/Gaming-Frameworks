#ifndef _MOUSE_EVENT_H
#define _MOUSE_EVENT_H

#include "../../../Common/Base/Event.h"

class MouseEvent:

	public Event< MouseEvent > {

	private:
		int button;
		int state;
		int x;
		int y;
		
	public:
		MouseEvent( int button, int state, int x, int y ) :
			Event< MouseEvent >( std::chrono::high_resolution_clock::now() ), button{ button }, state{ state }, x{ x }, y{ y } {
			set_id("MOUSE");
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

#endif
