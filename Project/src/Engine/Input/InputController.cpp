#include "Events/InputCommandHandler.h"
#include "Events/InputUpdateHandler.h"
#include "InputController.h"
#include "InputModel.h"

InputController::InputController() {
	auto table = StringTable::GetInstance();
	auto model = InputModel::GetInstance();

	// 
	auto id = InputCommand::GetID();
	auto handler = new InputCommandHandler( model );
	EventHandlerMap::AddEventHandler( id, handler );

	// 
	auto id2 = InputUpdate::GetID();
	auto handler2 = new InputUpdateHandler( model );
	EventHandlerMap::AddEventHandler( id2, handler2 );
}
