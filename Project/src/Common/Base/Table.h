#ifndef _TABLE_H
#define _TABLE_H

#include "../Types/Types.h"

#include <unordered_map>

/* 
 */
template < typename T >
class TableIterator {

private:

	typename std::unordered_map< StringID, T >::iterator iterator;

public:

	TableIterator( typename std::unordered_map< StringID, T >::iterator iterator ) :
		iterator{ iterator } {
	}
	TableIterator( const TableIterator< T > & other ) {
		iterator = other.iterator;
	}
	~TableIterator() {
	}
	StringID get_id() {
		return iterator->first;
	}
	T & get_value() {
		return iterator->second;
	}
	TableIterator< T > & operator=( const TableIterator< T > & other) {
		iterator = other.iterator;
		return *this;
	}
	bool operator==( const TableIterator< T > & other) {
		return iterator == other.iterator;
	}
	bool operator!=( const TableIterator< T > & other) {
		return iterator != other.iterator;
	}
	TableIterator< T > & operator*() {
		return *this;
	}
    TableIterator< T > & operator++() {
    	iterator++;
        return *this;
    }
};

/* 
 */
template < typename T >
class ConstTableIterator {

private:

	typename std::unordered_map< StringID, T >::const_iterator iterator;

public:

	ConstTableIterator( typename std::unordered_map< StringID, T >::const_iterator iterator ) :
		iterator{ iterator } {
	}
	ConstTableIterator( const ConstTableIterator< T > & other ) {
		iterator = other.iterator;
	}
	~ConstTableIterator() {
	}
	StringID get_id() {
		return iterator->first;
	}
	const T & get_value() {
		return iterator->second;
	}
	ConstTableIterator< T > & operator=( const ConstTableIterator< T > & other) {
		iterator = other.iterator;
		return *this;
	}
	bool operator==( const ConstTableIterator< T > & other) const {
		return iterator == other.iterator;
	}
	bool operator!=( const ConstTableIterator< T > & other) const {
		return iterator != other.iterator;
	}
	ConstTableIterator< T > & operator*() {
		return *this;
	}
    ConstTableIterator< T > & operator++() {
    	iterator++;
        return *this;
    }
};

/* A generic hash table which uses hashed strings as keys
 */
template < typename T >
class Table {

private:

	typename std::unordered_map< StringID, T > items;

public:
	
	virtual ~Table() {
	}
	void add( const StringID id, const T & item ) {
		items.emplace( id, T( item ) );
	}
	void remove( const StringID id ) {
		items.erase( id );
	}
	bool has( const StringID id ) const {
		return items.find( id ) != items.end();
	}
	TableIterator< T > get( const StringID id ) {
		return TableIterator< T >( items.find( id ) );
	}
	const ConstTableIterator< T > get( const StringID id ) const {
		return ConstTableIterator< T >( items.find( id ) );
	}
	TableIterator< T > begin() {
		return TableIterator< T >( items.begin() );
	}
	const ConstTableIterator< T > begin() const {
		return ConstTableIterator< T >( items.begin() );
	}
	TableIterator< T > end() {
		return TableIterator< T >( items.end() );
	}
	const ConstTableIterator< T > end() const {
		return ConstTableIterator< T >( items.end() );
	}
};

#endif
