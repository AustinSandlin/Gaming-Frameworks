#ifndef _INPUT_UPDATE_H
#define _INPUT_UPDATE_H

#include "../../../Common/Events/Event.h"

class InputUpdate : public Event {
public:
	InputUpdate() {}
	static StringID GetID() {
		static auto table = StringTable::GetInstance();
		static auto id = table.GetStringID( "InputUpdate" );
		return id;
	}
};

#endif
