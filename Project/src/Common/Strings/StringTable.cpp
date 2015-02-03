#include "StringTable.h"

#include <boost/crc.hpp>

void StringTable::AddString( const String & string ) {
	auto id = GetStringID( string );
	auto it = table.find( id );
	if ( it == table.end() ) {
		table[ id ] = string;
	}
}

void StringTable::RemoveString( const StringID id ) {
	auto it = table.find( id );
	if ( it != table.end() ) {
		table.erase( it );
	}
}

const String StringTable::GetString( StringID id ) const {
	auto it = table.find( id );
	if ( it == table.end() ) {
		return NULL;
	}
	else {
		return it->second;
	}
}

const StringID StringTable::GetStringID( const String & string ) const {
	boost::crc_32_type result;
	result.process_bytes( string.data(), string.length() );
	return result.checksum();
}
