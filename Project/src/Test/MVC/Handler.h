#ifndef _HANDLER_H
#define _HANDLER_H

template < typename T >
class Handler {

public:
	virtual void handle( T const & event ) = 0;
};

#endif
