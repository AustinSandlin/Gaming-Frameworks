#include "StringTable.h"

#include <string>

StringTable::~StringTable() {
	for ( auto it = table.begin(); it != table.end(); it++ ) {
		delete[] it->second;
	}
}

void StringTable::AddString( const String str ) {
	auto id = GetStringID( str );
	auto it = table.find( id );
	if ( it == table.end() ) {
		table[ id ] = strdup( str );
	}
}

void StringTable::RemoveString( const StringID id ) {
	auto it = table.find( id );
	if ( it != table.end() ) {
		delete[] it->second;
		table.erase( it );
	}
}

StringID StringTable::GetStringID( const String str ) const {
	return /* CRC-32 */;
}

const String StringTable::GetString( StringID id ) const {
	auto it = table.find( id );
	if ( id == table.end() ) {
		return NULL;
	}
	else {
		return it->second;
	}
}
