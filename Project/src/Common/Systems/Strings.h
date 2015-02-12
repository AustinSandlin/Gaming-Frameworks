#ifndef _STRINGS_H
#define _STRINGS_H

#include "../Base/Singleton.h"
#include "../Base/Table.h"

#include <boost/crc.hpp>

class Strings:

	public Singleton< Strings >,
	protected Table< String > {

private:
	
	friend class Singleton< Strings >;
	Strings() {
	}
	StringID hash( String string ) {
		boost::crc_32_type result;
		result.process_bytes( string.data(), string.length() );
		return result.checksum();
	}

public:
	
	StringID intern( String string ) {
		auto id = hash( string );
		Table< String >::add( id, string );
		return id;
	}
	bool has( StringID id ) {
		return Table< String >::has( id );
	}
	String lookup( StringID id ) {
		return Table< String >::get( id ).get_value();
	}
};

#endif
