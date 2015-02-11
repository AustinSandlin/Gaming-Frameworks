#include "Handler.h"
#include "Singleton.h"
#include "Table.h"

#include <iostream>


class Model;
class View;
class Controller;


class AddEntry {

private:
	StringID id;
	int value;

public:
	AddEntry( StringID id, int value ) :
		id{ id }, value{ value } {
	}
	const StringID get_id() const {
		return id;
	}
	const int get_value() const {
		return value;
	}
};


class Model :
	protected Singleton< Model >,
	protected Table< int > {

private:
	friend class Singleton< Model >;
	friend class Controller;
	friend class View;
	Model() {
	}
};


class View :
	public Singleton< View > {

private:
	friend class Singleton< View >;
	View() {
	}

public:
	const Table< int > & get_int_table() {
		static auto & model = Model::instance();
		return model;
	}
};


class Controller :
	public Singleton< Controller >,
	public Handler< AddEntry > {

private:
	friend class Singleton< Controller >;
	Controller() {
	}

public:
	void handle( const AddEntry & event ) {
		static auto & model = Model::instance();
		model.add( event.get_id(), event.get_value() );
		model.print();
	}
};


int main() {
	auto & controller = Controller::instance();
	auto & view = View::instance();

	controller.handle( AddEntry( 0, 0 ) );
	controller.handle( AddEntry( 1, 1 ) );

	auto & table = view.get_int_table();
	for ( auto it : table ) {
		std::cout << it.id() << ": " << it.value() << std::endl;
	}

	// Trying to call functions such as add() will generate a compiler error because they aren't marked as const
	//table.add( 2, 2 );

	return 0;
}
