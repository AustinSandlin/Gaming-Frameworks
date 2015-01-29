#ifndef _STRING_TABLE_H
#define _STRING_TABLE_H

#include "String.h"

#include <unordered_map>

using namespace std;

class StringTable {
public:
	static StringTable & GetInstance() {
		static StringTable singleton;
		return singleton;
	}
	~StringTable();
	void AddString( const String str );
	void RemoveString( const StringID id );
	StringID GetStringID( const String str ) const;
	const String GetString( const StringID id ) const;
private:
	StringTable() {}
	unordered_map< StringID, String > table;
};

#endif
