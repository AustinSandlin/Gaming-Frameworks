#include "Events/InputUpdate.h"

InputController::InputController() {
	auto table = StringTable::GetInstance();
	auto id = table.GetStringID( InputUpdate::ID );
	auto model = InputModel::GetInstance();
	auto handler = new InputUpdateHandler( model );
	EventHandlerMap::AddEventHandler( id, handler );
}
