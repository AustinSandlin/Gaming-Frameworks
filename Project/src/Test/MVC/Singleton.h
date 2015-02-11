#ifndef _SINGLETON_H
#define _SINGLETON_H

template < typename T >
class Singleton {

public:
	static T & instance() {
		static T singleton;
		return singleton;
	}

protected:
	Singleton() {
	}
};

#endif
