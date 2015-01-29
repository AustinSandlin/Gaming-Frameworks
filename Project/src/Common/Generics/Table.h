#ifndef _TABLE_H
#define _TABLE_H

#include "String.h"

#include <unordered_map>

using namespace std;

template < class T > class Table {
protected:
	HashTable() {}
	~HashTable() {}
	void Add( StringID id, T * element ) {
		auto it = elements.find( id );
		if ( it == elements.end() ) {
			elements[ id ] = element;
		}
	}
	T * Remove( StringID id ) {
		auto it = table.find( id );
		if ( it != table.end() ) {
			auto element = it.second;
			elements.erase( it );
			return element;
		}
		else {
			return NULL;
		}
	}
	T * Get( StringID id ) {
		auto it = table.find( id );
		if ( it != table.end() ) {
			return it.second;
		}
		else {
			return NULL;
		}
	}
private:
	unordered_map< StringID, T * > elements;
};

#endif
