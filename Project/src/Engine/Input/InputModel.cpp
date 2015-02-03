#include "InputModel.h"

void InputModel::PushCommand( InputCommand * command ) {
	commands.push( command );
}

void InputModel::PopCommand() {
	commands.pop();
}

bool InputModel::HasCommands() {
	return commands.size() > 0;
}

InputCommand * InputModel::NextCommand() {
	return commands.front();
}
