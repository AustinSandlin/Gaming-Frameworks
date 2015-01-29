#ifndef _EVENT_HANDLER_MAP_H
#define _EVENT_HANDLER_MAP_H

#include "EventHandler.h"

#include <unordered_map>
#include <vector>

using namespace std;

class EventHandlerMap : public EventHandler {
public:
	virtual ~EventHandlerMap();
	void AddEventHandler( StringID id, EventHandler * handler );
	void RemoveEventHandler( StringID id );
	void HandleEvent( Event * event );
private:
	unordered_map< StringID, vector< EventHandler * > > handlers;
};

#endif
