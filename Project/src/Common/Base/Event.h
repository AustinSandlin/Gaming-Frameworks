#ifndef _EVENT_H
#define _EVENT_H

#include "../Types/Types.h"

template< typename T >
class Event {

private:

	TimeStamp time;

protected:

	Event( TimeStamp time ) :
		time{ time } {
	}

public:

	bool operator>( const T & other ) const {
		return time > other.time;
	}
	bool operator<( const T & other ) const {
		return time < other.time;
	}
	TimeStamp get_time() {
		return time;
	}
};

#endif
