#ifndef _QUEUE_H
#define _QUEUE_H

#include <queue>
#include <vector>

template< typename T >
class Queue {

private:

	std::priority_queue< T, std::vector< T >, std::greater< T > > queue;

public:
	
	bool empty() const {
		return queue.empty();
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