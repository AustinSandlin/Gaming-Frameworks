#ifndef _EVENT_H
#define _EVENT_H

#include "../Types/Time.h"

class Event {

private:

	TimeStamp time;	

protected:

	Event( TimeStamp time ) :
		time{ time } {
	}

public:

	bool operator>( T const & other ) {
		return time > other.time );
	}
	bool operator<( T const & other ) {
		return time < other.time );
	}
	TimeStamp get_time() {
		return time;
	}
};

#endif
