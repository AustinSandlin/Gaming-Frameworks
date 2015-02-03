#include "EventHandlerMap.h"

EventHandlerMap::~EventHandlerMap() {
	for ( auto it = handlers.begin(); it != handlers.end(); it++ ) {
		for ( auto it2 = it->second.begin(); it2 != it->second.end(); it2++ ) {
			delete *it2;
		}
	}
}

void EventHandlerMap::AddEventHandler( StringID id, EventHandler * handler ) {
	auto it = handlers.find( id );
	if ( it == handlers.end() ) {
		handlers[ id ].push_back( handler );
	}
}

void EventHandlerMap::RemoveEventHandler( StringID id ) {
	auto it = handlers.find( id );
	if ( it != handlers.end() ) {
		for ( auto it2 = it->second.begin(); it2 != it->second.end(); it2++ ) {
			delete *it2;
		}
	}
}

void EventHandlerMap::HandleEvent( Event & event ) {
	auto id = event.GetID();
	auto it = handlers.find( id );
	if ( it != handlers.end() ) {
		for ( auto it2 = it->second.begin(); it2 != it->second.end(); it2++ ) {
			(*it2)->HandleEvent( event );
		}
	}
}
