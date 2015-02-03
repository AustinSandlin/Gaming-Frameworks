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
	void PushCommand( InputCommand * command );
	void PopCommand();
	bool HasCommands();
	InputCommand * NextCommand();
private:
    InputModel() {}
	std::queue< InputCommand * > commands;
};

#endif
