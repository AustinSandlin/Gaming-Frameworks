#include "View.h"
#include "Model.h"

using namespace Input;

const Table< KeyboardActionQueue > & View::get_keyboard_action_queues() const {
	static auto & model = Model::instance();
	return model.get_table< KeyboardActionQueue >();
}

const Table< MouseActionQueue > & View::get_mouse_action_queues() const {
	static auto & model = Model::instance();
	return model.get_table< MouseActionQueue >();
}
