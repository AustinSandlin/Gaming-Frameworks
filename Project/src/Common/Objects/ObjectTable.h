#ifndef _OBJECT_TABLE_H
#define _OBJECT_TABLE_H

#include "Object.h"

class ObjectTable {
public:
	static ObjectTable & GetInstance() {
		static ObjectTable singleton;
		return singleton;
	}
	~ObjectTable();
	void AddObject( Object * obj );
	void RemoveObject( StringID id );
	Object * GetObject( StringID id );
private:
	ObjectTable() {}
	unordered_map< StringID, Object * > table;
};

#endif
