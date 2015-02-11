#ifndef _SINGLETON_H
#define _SINGLETON_H

template < typename T >
class Singleton {

protected:
	
	Singleton() {
	}
	
public:

	static T & instance() {
		static T singleton;
		return singleton;
	}
};

#endif
