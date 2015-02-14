#ifndef _KEYBOARD_EVENT_H
#define _KEYBOARD_EVENT_H

#include "../../../Common/Base/Event.h"

class KeyboardEvent:
	public Event< KeyboardEvent > {
		
	private:
		
		unsigned char key;
		int x;
		int y;

	public:
		KeyboardEvent( const unsigned char key, const int x, const int y ) :
			Event< KeyboardEvent >( std::chrono::high_resolution_clock::now() ), key{ key }, x{ x }, y{ y } {
			//I hate this. Can't send const uchar as a string.
			String temp = "";
			temp += key;
			set_id(temp);
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

#endif