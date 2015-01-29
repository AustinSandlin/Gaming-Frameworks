#ifndef	_EVENT_H
#define _EVENT_H

#include "../Strings/String.h"

class Event {
public:
	StringID GetID() { return id; }
protected:
	Event( StringID id ) : id{ id } {};
private:
	StringID id;
};

#endif
