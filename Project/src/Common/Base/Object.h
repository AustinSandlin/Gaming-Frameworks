#ifndef _OBJECT_H
#define _OBJECT_H

#include "Property.h"

class Object {

private:

	StringID id;
	Table< Property > properties;

protected:

	Object( StringID id ) : id { id } {
	}

public:
	
    StringID getID() const {
        return id;
    }
    void addProperty( StringID id, Property property ) {
    	properties.add( id, property );
    }
    void removeProperty( StringID id ) {
    	properties.remove( id );
    }
    bool hasProperty( StringID id ) const {
    	return properties.has( id );
    }
    Property & getProperty( StringID id ) {
		return properties.get( id ).getValue();
    }
};

#endif
