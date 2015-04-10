#ifndef _TRIGGER_CONTROLLER_H
#define _TRIGGER_CONTROLLER_H

#include "../../Common/Base/Command.h"
#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Types.h"

#include "Triggers/BooleanTrigger.h"
#include "Triggers/IntegerTrigger.h"
#include "Triggers/FloatTrigger.h"
#include "Triggers/CollisionTrigger.h"

class TriggerController:

	public Singleton< TriggerController > {

private:

	friend Singleton< TriggerController >;

	Table< BooleanTrigger > boolean_triggers;
	Table< IntegerTrigger > integer_triggers;
	Table< FloatTrigger > float_triggers;
	Table< CollisionTrigger > collision_triggers;

	TriggerController() {
	}

public:

	void addBooleanTrigger( String name, String variable, String comparison, bool value );
	void addIntegerTrigger( String name, String variable, String comparison, long value );
	void addFloatTrigger( String name, String variable, String comparison, double value );
	void addCollisionTrigger( String name, String first, String second );

	void removeBooleanTrigger( String name );
	void removeIntegerTrigger( String name );
	void removeFloatTrigger( String name );
	void removeCollisionTrigger( String name );

	void setBooleanTrigger( String name, Command * command );
	void setIntegerTrigger( String name, Command * command );
	void setFloatTrigger( String name, Command * command );
	void setCollisionTrigger( String name, Command * command );

	void updateBooleanTriggers( String variable );
	void updateIntegerTriggers( String variable );
	void updateFloatTriggers( String variable );
	void updateCollisionTriggers( String first, String second );
};

#endif
