#ifndef	_EVENT_PARAMETER_H
#define _EVENT_PARAMETER_H

#include "../Strings/String.h"

class EventParameter {
public:
	StringID GetType() { return type; }
	EventParemeter GetValue() { return value; }
protected:
	EventParameter( StringID id ) : id{ id } {};
private:
	StringID id;
	
};

#endif
