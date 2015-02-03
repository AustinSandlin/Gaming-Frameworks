#ifndef _STRING_TABLE_H
#define _STRING_TABLE_H

#include "String.h"

#include <unordered_map>

class StringTable {
public:
	static StringTable & GetInstance() {
		static StringTable singleton;
		return singleton;
	}
	~StringTable() {}
	void AddString( const String & string );
	void RemoveString( const StringID id );
	const String GetString( const StringID id ) const;
	const StringID GetStringID( const String & string ) const;
private:
	StringTable() {}
	std::unordered_map< StringID, String > table;
};

#endif
