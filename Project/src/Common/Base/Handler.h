#ifndef _HANDLER_H
#define _HANDLER_H

template < typename T >
class Handler {

public:
	virtual void handle( const T & event ) = 0;
};

#endif
