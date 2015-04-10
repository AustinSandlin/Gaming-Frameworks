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
	
	// bool empty( TimeStamp limit ) const {
	// 	if ( !queue.empty() ) {
	// 		return ( queue.top() < limit );
	// 	}
	// 	else {
	// 		return true;
	// 	}
	// }
	bool empty() const {
		// static Clock& clock = Clock::instance();
		return queue.empty(); //empty( clock.getCurrentFrame() );
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
