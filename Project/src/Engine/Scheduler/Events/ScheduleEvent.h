
template< typename S, typename T >
class Schedule:

	public Event {

private:

	S controller;
	T event;

public:

	Schedule( const S & controller, const T & event ) :
		Event( 0 ), controller{ controller }, event{ event } {
	}
	const S & get_controller() const {
		return controller;
	}
	const T & get_event() const {
		return event;
	}
};
