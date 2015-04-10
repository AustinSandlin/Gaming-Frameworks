#ifndef _COLLISION_TRIGGER_H
#define _COLLISION_TRIGGER_H

#include "../../../Common/Base/Command.h"
#include "../../../Common/Base/Types.h"

#include "../../Variable/VariableController.h"

#include <list>

class CollisionTrigger {

private:

	String first;
	String second;
	std::list< Command * > commands;

public:

	CollisionTrigger( String first, String second ) {
		this->first = first;
		this->second = second;
	}

	~CollisionTrigger() {

		// 
		for ( Command * command : commands ) {
			delete command;
		}
	}

	void addCommand( Command * command ) {

		// 
		if ( command != NULL ) {
			commands.push_back( command );
		}
	}

	void runCommands() {

		// 
		for ( Command * command : commands ) {
			command->run();
		}
	}

	bool hasObjects( String first, String second ) {

		// 
		if ( this->first == first && this->second == second ) {
			return true;
		}
		else if ( this->first == second && this->second == first ) {
			return true;
		}

		// 
		return false;
	}
};

#endif
