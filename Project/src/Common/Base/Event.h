#ifndef _EVENT_H
#define _EVENT_H

#include "../Resources/Clock.h"
#include "../Resources/Strings.h"

class Event {

private:

	static strings = Strings::instance();
	static clock = Clock::instance();

	StringID id;
	TimeStamp time;

protected:

	Event( String name ) : id{ strings.intern( name ) }, time{ clock.getTime() } {
	}
	Event( String name, TimeStamp time ) : id{ strings.intern( name ) }, time{ time } {
	}

public:

	bool operator>( const Evetn & other ) const {
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
