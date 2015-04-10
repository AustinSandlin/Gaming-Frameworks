#ifndef _EVENT_H
#define _EVENT_H

#include "../Resources/Clock.h"
#include "../Resources/Strings.h"

class Event {

private:

	StringID id;
	TimeStamp time;

protected:

	Event() {

	}

	Event( String name ) {
		static Strings& strings = Strings::instance();
		static Clock& clock = Clock::instance();
		
		id = strings.intern( name );
		time = clock.getTime();
	}
	Event( String name, TimeStamp time ) : time{ time } {
		static Strings& strings = Strings::instance();

		id = strings.intern( name );
	}

	void setID(const String name) {
		static Strings& strings = Strings::instance();
		id = strings.intern(name);
	}

public:

	bool operator>( const Event & other ) const {
		return time > other.time;
	}
	bool operator<( const Event & other ) const {
		return time < other.time;
	}
	bool operator>( const TimeStamp & other ) const {
		return time > other;
	}
	bool operator<( const TimeStamp & other ) const {
		return time < other;
	}
	StringID getID() const {
		return id;
	}
	TimeStamp getTime() const {
		return time;
	}
};



#endif
