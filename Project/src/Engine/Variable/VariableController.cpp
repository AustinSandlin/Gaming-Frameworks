#include "VariableController.h"

#include "../../Common/Resources/Strings.h"

void VariableController::addBooleanVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( !boolean_variables.has( id ) ) {
    	boolean_variables.add( id, true );
    }
}

void VariableController::removeBooleanVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( boolean_variables.has( id ) ) {
    	boolean_variables.remove( id );
    }
}

bool VariableController::hasBooleanVariable( String name ) {

    // 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    return boolean_variables.has( id );
}

bool VariableController::getBooleanVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
	return boolean_variables.get( id ).getValue();
}

void VariableController::setBooleanVariable( String name, bool value ) {

    // 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( boolean_variables.has( id ) ) {
        boolean_variables.get( id ).getValue() = value;
    }
}

void VariableController::addIntegerVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( !integer_variables.has( id ) ) {
    	integer_variables.add( id, 0 );
    }
}

void VariableController::removeIntegerVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( integer_variables.has( id ) ) {
    	integer_variables.remove( id );
    }
}


bool VariableController::hasIntegerVariable( String name ) {

    // 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    return integer_variables.has( id );
}

long VariableController::getIntegerVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
	return integer_variables.get( id ).getValue();
}

void VariableController::setIntegerVariable( String name, long value ) {

    // 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( integer_variables.has( id ) ) {
        integer_variables.get( id ).getValue() = value;
    }
}

void VariableController::addFloatVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( !float_variables.has( id ) ) {
    	float_variables.add( id, 0.0 );
    }
}

void VariableController::removeFloatVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( float_variables.has( id ) ) {
    	float_variables.remove( id );
    }
}

bool VariableController::hasFloatVariable( String name ) {

    // 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    return float_variables.has( id );
}

double VariableController::getFloatVariable( String name ) {

	// 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
	return float_variables.get( id ).getValue();
}

void VariableController::setFloatVariable( String name, double value ) {

    // 
    static Strings & strings = Strings::instance();

    // 
    StringID id = strings.intern( name );
    if ( float_variables.has( id ) ) {
        float_variables.get( id ).getValue() = value;
    }
}
