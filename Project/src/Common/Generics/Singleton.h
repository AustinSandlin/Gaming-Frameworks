
template <class T>
class Singleton {
public:
	static T & GetInstance() {
		static T singleton;
		return singleton;
	}
protected:
	Singleton() {}
};