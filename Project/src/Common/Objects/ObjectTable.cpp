#include "ObjectTable.h"

ObjectTable::~ObjectTable() {
	for ( auto it = table.begin(); it != table.end(); it++ ) {
		delete[] it->second;
	}
}

void ObjectTable::AddObject( Object * obj ) {
	auto id = GetStringID( str );
	auto it = table.find( id );
	if ( it == table.end() ) {
		table[ id ] = obj;
	}
}

void ObjectTable::RemoveObject( StringID id ) {
	auto it = table.find( id );
	if ( it != table.end() ) {
		// Release it->second, if necessary...
		table.erase( it );
	}
}

Object * ObjectTable::GetObject( StringID id ) {
	auto it = table.find( id );
	if ( id == table.end() ) {
		return NULL;
	}
	else {
		return it->second;
	}
}
