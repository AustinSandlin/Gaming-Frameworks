#ifndef _SINGLETON_H
#define _SINGLETON_H

template < class T > class Singleton {
public:
	static T & GetInstance() {
		static T singleton;
		return singleton;
	}
protected:
	Singleton() {}
	~Singleton() {}
private:
	Singleton( Singleton const & ) {}
};

#endif
