#ifndef _PROPERTIES_H
#define _PROPERTIES_H

#include "../Resources/Clock.h"

class Property {

private:

	StringID id;
    String name;
    String value;
	
protected:

	Property( StringID id, String name, String value ) : id{ id }, name{ name }, value{ value } {
	}

public:

    StringID getID() const {
        return id;
    }
    /*
    TypeName getType() const {
        return name;
    }




    void setInteger( const int & val ) {
        value.integer = val;
    }
    int & getInteger() {
        if ( type != INTEGER ) {
            assert( false );
        }
        return value.integer;
    }
    */
};

#endif