#ifndef _INPUT_KEYBOARD_ACTION_H
#define _INPUT_KEYBOARD_ACTION_H

#include "../../../Common/Base/Event.h"

namespace Input {
	
	class KeyboardAction:

		public Event {
			
	private:
		
		unsigned char key;
		int x;
		int y;

	public:
		KeyboardAction( unsigned char key, int x, int y ) :
			key{ key }, x{ x }, y{ y } {
		}
		unsigned char get_key() {
			return key;
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
