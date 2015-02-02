#ifndef _OBJECT_PROPERTY_TABLE_H
#define _OBJECT_PROPERTY_TABLE_H

#include <unordered_map>
#include "ObjectProperty.h"

using namespace std;

class ObjectPropertyTable {
public:
	static ObjectPropertyTable & GetInstance() {
		static ObjectPropertyTable singleton;
		return singleton;
	}
	~ObjectPropertyTable();
	void AddObject( ObjectProperty * prop );
	void RemoveObject( StringID id );
	ObjectProperty * GetObject( StringID id );
private:
	ObjectPropertyTable() {}
	unordered_map< StringID, ObjectProperty * > table;
};

#endif
