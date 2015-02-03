#ifndef _OBJECT_H
#define _OBJECT_H

#include <unordered_map>
#include "ObjectProperty.h"

using namespace std;

class Object {
public:
	Object( StringID id ) : id{ id } {}
	~Object();
	const StringID GetID() { return id; };
	void SetProperty( ObjectProperty* property );
	void ClearProperty( StringID id );
	ObjectProperty * GetProperty( StringID id );
private:
	StringID id;
	unordered_map< StringID, ObjectProperty* > properties;
};

#endif
