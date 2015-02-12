#ifndef _INPUT_KEYBOARD_ACTION_H
#define _INPUT_KEYBOARD_ACTION_H

#include "../../../Common/Base/Event.h"

namespace Input {
	
	class KeyboardAction:

		public Event< KeyboardAction > {
			
	private:
		
		unsigned char key;
		int x;
		int y;

	public:
		KeyboardAction( const unsigned char key, const int x, const int y ) :
			Event< KeyboardAction >( 0 ), key{ key }, x{ x }, y{ y } {
		}
		const unsigned char get_key() const {
			return key;
		}
		const int get_x() const {
			return x;
		}
		const int get_y() const {
			return y;
		}
	};
}

#endif
