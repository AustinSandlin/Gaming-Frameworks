#ifndef _PROPERTIES_H
#define _PROPERTIES_H

#include "../Types/Types.h"

class Property {

private:

	StringID id;
    String name;
    String value;
	
protected:

	Property( StringID id, String name, String value) :
        id{ id }, name{ name }, value{ value }{
	}

public:

    StringID get_id() const {
        return id;
    }    
    String get_name() const {
        return name;
    }
    String get_value() const {
        return value;
    }

    void set_value( String val) {
        value = val;
    }
};

#endif
