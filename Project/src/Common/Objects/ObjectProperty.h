#ifndef _OBJECT_PROPERTY_H
#define _OBJECT_PROPERTY_H

#include "Object.h"

class ObjectProperty {
public:
	StringID GetID() { return id; }
protected:
	ObjectProperty( StringID id ) : id{ id } {};
private:
	StringID id;
};

#endif
