#ifndef _MOUSE_EVENT_H
#define _MOUSE_EVENT_H

#include "../../../Common/Base/Event.h"

class MouseEvent:

	public Event {

	private:

		static strings = 

		int button;
		int state;
		int x;
		int y;
		
	public:
		MouseEvent( int button, int state, int x, int y ) :
			Event( "MouseEvent" ), button{ button }, state{ state }, x{ x }, y{ y } {
		}
		int getButton() {
			return button;
		}
		int getState() {
			return state;
		}
		int getX() {
			return x;
		}
		int getY() {
			return y;
		}
};

#endif
