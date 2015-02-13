#ifndef _EVENT_H
#define _EVENT_H

#include "../Types/Types.h"
#include "../Resources/Strings.h"

template< typename T >
class Event {

private:

	StringID id;
	TimeStamp time;

protected:

	// static Strings& StrController;

	Event( TimeStamp time ) :
		time{ time } {
		// StrController = Strings::instance();
	}
	void set_id( String str ) {
		// id = StrController.intern(str);
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
	StringID get_id() const {
		return id;
	}
};

#endif
