#ifndef _INPUT_MODEL_H
#define _INPUT_MODEL_H

#include "Events/InputCommand.h"

#include <queue>

class InputModel {
public:
	static InputModel & GetInstance() {
		static InputModel singleton;
		return singleton;
	}
	bool HasCommands();
	void PushCommand( InputCommand * command );
	InputCommand * PopCommand();
private:
    InputModel() {}
	std::queue< InputCommand * > commands;
};

#endif
