#ifndef _OBJECT_PROPERTY_TABLE_H
#define _OBJECT_PROPERTY_TABLE_H

#include "ObjectProperty.h"

class ObjectPropertyTable {
public:
	static ObjectPropertyTable & GetInstance() {
		static ObjectPropertyTable singleton;
		return singleton;
	}
	~ObjectPropertyTable();
	void AddProperty( ObjectProperty * prop );
	void RemoveProperty( StringID id );
	ObjectProperty * GetProperty( StringID id );
private:
	ObjectPropertyTable() {}
	unordered_map< StringID, ObjectProperty * > table;
};

#endif
