#include "Events/InputUpdate.h"

InputController::InputController() {
	auto table = StringTable::GetInstance();
	auto model = InputModel::GetInstance();
	auto id = InputUpdate::GetID();
	auto handler = new InputUpdateHandler( model );
	EventHandlerMap::AddEventHandler( id, handler );
}
