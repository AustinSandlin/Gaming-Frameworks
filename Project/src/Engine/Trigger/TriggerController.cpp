#include "TriggerController.h"

#include "../../Common/Resources/Strings.h"

void TriggerController::addBooleanTrigger( String name, String variable, String comparison, bool value ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( !boolean_triggers.has( id ) ) {
    	boolean_triggers.add( id, BooleanTrigger( variable, comparison, value ) );
    }
}

void TriggerController::addIntegerTrigger( String name, String variable, String comparison, long value ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( !integer_triggers.has( id ) ) {
    	integer_triggers.add( id, IntegerTrigger( variable, comparison, value ) );
    }
}

void TriggerController::addFloatTrigger( String name, String variable, String comparison, double value ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( !float_triggers.has( id ) ) {
    	float_triggers.add( id, FloatTrigger( variable, comparison, value ) );
    }
}

void TriggerController::addCollisionTrigger( String name, String first, String second ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( !collision_triggers.has( id ) ) {
    	collision_triggers.add( id, CollisionTrigger( first, second ) );
    }
}

void TriggerController::removeBooleanTrigger( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( boolean_triggers.has( id ) ) {
    	boolean_triggers.remove( id );
    }
}

void TriggerController::removeIntegerTrigger( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( integer_triggers.has( id ) ) {
    	integer_triggers.remove( id );
    }
}

void TriggerController::removeFloatTrigger( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( float_triggers.has( id ) ) {
    	float_triggers.remove( id );
    }
}

void TriggerController::removeCollisionTrigger( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( collision_triggers.has( id ) ) {
    	collision_triggers.remove( id );
    }
}

void TriggerController::setBooleanTrigger( String name, Command * command ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( boolean_triggers.has( id ) ) {
    	boolean_triggers.get( id ).getValue().addCommand( command );
    }
}

void TriggerController::setIntegerTrigger( String name, Command * command ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( integer_triggers.has( id ) ) {
    	integer_triggers.get( id ).getValue().addCommand( command );
    }
}

void TriggerController::setFloatTrigger( String name, Command * command ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( float_triggers.has( id ) ) {
    	float_triggers.get( id ).getValue().addCommand( command );
    }
}

void TriggerController::setCollisionTrigger( String name, Command * command ) {
	
	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( collision_triggers.has( id ) ) {
    	collision_triggers.get( id ).getValue().addCommand( command );
    }
}

void TriggerController::updateBooleanTriggers( String variable ) {

    // 
    for ( auto & it : boolean_triggers ) {

        // 
        BooleanTrigger & trigger = it.getValue();
    	if ( trigger.hasVariable( variable ) && trigger.hasFired() ) {
    		trigger.runCommands();
    	}
    }
}

void TriggerController::updateIntegerTriggers( String variable ) {
    
    // 
    for ( auto & it : integer_triggers ) {

        // 
        IntegerTrigger & trigger = it.getValue();
    	if ( trigger.hasVariable( variable ) && trigger.hasFired() ) {
    		trigger.runCommands();
    	}
    }
}

void TriggerController::updateFloatTriggers( String variable ) {
    
    // 
    for ( auto & it : float_triggers ) {

        // 
        FloatTrigger & trigger = it.getValue();
    	if ( trigger.hasVariable( variable ) && trigger.hasFired() ) {
    		trigger.runCommands();
    	}
    }
}

void TriggerController::updateCollisionTriggers( String first, String second ) {
    
    // 
    for ( auto & it : collision_triggers ) {

        // 
        CollisionTrigger & trigger = it.getValue();
    	if ( trigger.hasObjects( first, second ) ) {
    		trigger.runCommands();
    	}
    }
}
