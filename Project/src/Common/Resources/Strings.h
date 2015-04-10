#ifndef _STRINGS_H
#define _STRINGS_H

#include "../Base/Singleton.h"
#include "../Base/Table.h"

class Strings:

	public Singleton< Strings >,
	protected Table< String > {

private:
	
	friend class Singleton< Strings >;
	Strings() {
	}

public:
	
	StringID intern( String string ) {
		std::hash<String> hash_fn;
		StringID id = hash_fn( string );
		Table< String >::add( id, string );
		return id;
	}
	bool has( StringID id ) {
		return Table< String >::has( id );
	}
	String lookup( StringID id ) {
		return Table< String >::get( id ).getValue();
	}
};

#endif
