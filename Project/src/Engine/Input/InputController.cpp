#include "Events/InputCommandHandler.h"
#include "Events/InputUpdateHandler.h"
#include "InputController.h"
#include "InputModel.h"

InputController::InputController() {
	
	// 
	auto id = InputCommand::GetID();
	auto handler = new InputCommandHandler();
	EventHandlerMap::AddEventHandler( id, handler );

	// 
	auto id2 = InputUpdate::GetID();
	auto handler2 = new InputUpdateHandler();
	EventHandlerMap::AddEventHandler( id2, handler2 );
}
