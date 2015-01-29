#include "ObjectPropertyTable.h"

ObjectPropertyTable::~ObjectPropertyTable() {
	for ( auto it = table.begin(); it != table.end(); it++ ) {
		delete[] it->second;
	}
}

void ObjectPropertyTable::AddObject( ObjectProperty * prop ) {
	auto id = GetStringID( str );
	auto it = table.find( id );
	if ( it == table.end() ) {
		table[ id ] = obj;
	}
}

void ObjectPropertyTable::RemoveObject( StringID id ) {
	auto it = table.find( id );
	if ( it != table.end() ) {
		// Release it->second, if necessary...
		table.erase( it );
	}
}

Object * ObjectPropertyTable::GetObject( StringID id ) {
	auto it = table.find( id );
	if ( id == table.end() ) {
		return NULL;
	}
	else {
		return it->second;
	}
}
