#ifndef _QUEUE_H
#define _QUEUE_H

#include <queue>
#include <vector>

template< typename T >
class Queue {

private:

	std::priority_queue< T, std::vector< T >, std::greater< T > > queue;

public:
	
	void push( const T & item ) {
		queue.push( T( item ) )
	}
	void pop() {
		queue.pop();
	}
	T next() {
		queue.top();
	}
};

#endif
