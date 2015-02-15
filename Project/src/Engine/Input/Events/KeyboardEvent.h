#ifndef _KEYBOARD_EVENT_H
#define _KEYBOARD_EVENT_H

#include "../../../Common/Base/Event.h"

class KeyboardEvent:
	public Event {
		
	private:
		
		char key;
		int x;
		int y;

	public:
		KeyboardEvent( const char key, const int x, const int y ) :
			Event( String(&key) ), key{ key }, x{ x }, y{ y } {
			String temp = "";
			temp += key;
			setID(temp);
		}
		const char getKey() const {
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
