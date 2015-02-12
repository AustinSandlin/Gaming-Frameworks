#ifndef _SCHEDULER_CONTROLLER_H
#define _SCHEDULER_CONTROLLER_H

#include "../../Common/Base/Handler.h"
#include "../../Common/Base/Singleton.h"


#include "../Object/Events/AddProperty.h"
#include "../Object/Events/RemoveProperties.h"
#include "../Object/Events/RemoveProperty.h"

#include ""

namespace Scheduler {

	class Controller:
		
		public Singleton< Controller >,

		public Handler< Update >,

		public Handler< ScheduleEvent< Input::Controller, Object::AddProperty< Input::KeyboardActionQueue > > >,
		public Handler< ScheduleEvent< Input::Controller, Object::AddProperty< Input::MouseActionQueue > > >,
		public Handler< ScheduleEvent< Input::Controller, Object::RemoveProperty< Input::KeyboardActionQueue > > >,
		public Handler< ScheduleEvent< Input::Controller, Object::RemoveProperty< Input::MouseActionQueue > > >,
		public Handler< ScheduleEvent< Input::Controller, Input::PushAction< Input::KeyboardAction > > >,
		public Handler< ScheduleEvent< Input::Controller, Input::PushAction< Input::MouseAction > > >,
		public Handler< ScheduleEvent< Input::Controller, Input::PopAction< Input::KeyboardAction > > >,
		public Handler< ScheduleEvent< Input::Controller, Input::PopAction< Input::MouseAction > > > {

	private:

		friend class Singleton< Controller >;
		Controller() {
		}

	public:
		void handle( const Update & event );
		void handle( const ScheduleEvent< Input::Controller, Object::AddProperty< Input::KeyboardActionQueue > > & event );
		void handle( const ScheduleEvent< Input::Controller, Object::AddProperty< Input::MouseActionQueue > > & event );
		void handle( const ScheduleEvent< Input::Controller, Object::RemoveProperty< Input::KeyboardActionQueue > > & event );
		void handle( const ScheduleEvent< Input::Controller, Object::RemoveProperty< Input::MouseActionQueue > > & event );
		void handle( const ScheduleEvent< Input::Controller, Input::PushAction< Input::KeyboardAction > > & event );
		void handle( const ScheduleEvent< Input::Controller, Input::PushAction< Input::MouseAction > > & event );
		void handle( const ScheduleEvent< Input::Controller, Input::PopAction< Input::KeyboardAction > > & event );
		void handle( const ScheduleEvent< Input::Controller, Input::PopAction< Input::MouseAction > > & event );
	};
}

#endif
