#include "Events/InputUpdateEvent.h"

InputController::InputController() {
	auto table = StringTable::GetInstance();
	auto id = table.GetStringID( "InputUpdateEvent" );
	auto model = InputModel::GetInstance();
	auto handler = new InputUpdateHandler( model );
	EventHandlerMap::AddEventHandler( id, handler );
}
