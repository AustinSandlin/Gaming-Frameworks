#ifndef _KEYBOARD_EVENT_H
#define _KEYBOARD_EVENT_H

#include "../../../Common/Base/Event.h"

class KeyboardEvent:
	public Event {
		
	private:
		
		unsigned char key;
		int x;
		int y;

	public:
		KeyboardEvent( const unsigned char key, const int x, const int y ) :
			Event( "KeyboardEvent" ), key{ key }, x{ x }, y{ y } {
		}
		const unsigned char getKey() const {
			return key;
		}
		const int getX() const {
			return x;
		}
		const int getY() const {
			return y;
		}
};

#endif
