#ifndef _QUEUE_H
#define _QUEUE_H

#include "../Resources/Clock.h"

#include <queue>
#include <vector>

template< typename T >
class Queue {

private:

	std::priority_queue< T, std::vector< T >, std::greater< T > > queue;

public:
	
	bool empty( TimeStamp limit ) const {
		if ( !queue.empty() ) {
			return queue.next() < limit;
		}
		else {
			return true;
		}
	}
	bool empty() const {
		return empty( clock.getTime() );
	}
	void push( const T & item ) {
		queue.push( T( item ) );
	}
	void pop() {
		queue.pop();
	}
	const T & next() const {
		return queue.top();
	}
};

#endif
