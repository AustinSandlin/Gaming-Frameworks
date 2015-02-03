#ifndef _OBJECT_PROPERTY_H
#define _OBJECT_PROPERTY_H

#include "../Strings/String.h"

class ObjectProperty {
public:
	const StringID GetID() { return id; }
protected:
	ObjectProperty( StringID id ) : id{ id } {};
private:
	StringID id;
};

#endif
