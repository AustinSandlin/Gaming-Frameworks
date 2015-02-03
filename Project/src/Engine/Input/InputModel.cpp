#include "InputModel.h"

bool InputModel::HasCommands() {
	return !commands.empty();
}

void InputModel::PushCommand( InputCommand * command ) {
	commands.push( command );
}

InputCommand * InputModel::PopCommand() {
	auto command = commands.front();
	commands.pop();
	return command;
}
