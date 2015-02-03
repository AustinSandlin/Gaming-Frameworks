#ifndef	_EVENT_H
#define _EVENT_H

#include "../Strings/String.h"

class Event {
public:
	virtual ~Event() {}
	const StringID GetID() const { return id; }
	//void AddParameter( StringID id, EventParemeter parameter );
	//void RemoveParameter( StringID id );
	//const EventParemeter GetParameter( StringID id ) const;
protected:
	Event();
	Event( StringID id ) : id{ id } {};
private:
	StringID id;
	//unordered_map< StringID, EventParemeter > parameters;
};

#endif
