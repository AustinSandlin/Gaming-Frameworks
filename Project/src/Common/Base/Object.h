#ifndef _OBJECT_H
#define _OBJECT_H

#include "../Types/Types.h"

template< typename T >
class Object {

private:

	StringID id;

protected:

	Object( StringID id ) : id { id } {

	}

public:
    StringID get_id() {
        return id;
    }
};

#endif
