#ifndef _SCHEDULER_MODEL_H
#define _SCHEDULER_MODEL_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"

#include "Controller.h"
#include "View.h"

namespace Scheduler {

	class Model:

		private Singleton< Model >,
		private Queue< ScheduleEvent< Input::Controller, Object::AddProperty< Input::KeyboardActionQueue > > >,
		private Queue< ScheduleEvent< Input::Controller, Object::AddProperty< Input::MouseActionQueue > > >,
		private Queue< ScheduleEvent< Input::Controller, Object::RemoveProperty< Input::KeyboardActionQueue > > >,
		private Queue< ScheduleEvent< Input::Controller, Object::RemoveProperty< Input::MouseActionQueue > > >,
		private Queue< ScheduleEvent< Input::Controller, Object::RemoveProperties > >,
		private Queue< ScheduleEvent< Input::Controller, Input::PushAction< Input::KeyboardAction > > >,
		private Queue< ScheduleEvent< Input::Controller, Input::PushAction< Input::MouseAction > > >,
		private Queue< ScheduleEvent< Input::Controller, Input::PopAction< Input::KeyboardAction > > >,
		private Queue< ScheduleEvent< Input::Controller, Input::PopAction< Input::MouseAction > > > {

	private:
		
		friend class Singleton< Model >;
		friend class Controller;
		friend class View;
		Model() {
		}

	public:

		template< typename S, T >
		Table< T > & get_queue() {
			return *this;
		}
	};
}

#endif
