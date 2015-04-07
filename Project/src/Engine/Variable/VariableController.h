#ifndef _VARIABLE_CONTROLLER_H
#define _VARIABLE_CONTROLLER_H

#include "../../Common/Base/Singleton.h"
#include "../../Common/Base/Table.h"
#include "../../Common/Base/Types.h"

class VariableController:

	public Singleton< VariableController > {

private:

	friend Singleton< VariableController >;

	Table< bool > boolean_variables;
	Table< long > integer_variables;
	Table< double > float_variables;

	VariableController() {
	}

public:

	void addBooleanVariable( String name );
	void removeBooleanVariable( String name );
	bool hasBooleanVariable( String name );
	bool getBooleanVariable( String name );
	void setBooleanVariable( String name, bool value );

	void addIntegerVariable( String name );
	void removeIntegerVariable( String name );
	bool hasIntegerVariable( String name );
	long getIntegerVariable( String name );
	void setIntegerVariable( String name, long value );

	void addFloatVariable( String name );
	void removeFloatVariable( String name );
	bool hasFloatVariable( String name );
	double getFloatVariable( String name );
	void setFloatVariable( String name, double value );
};

#endif
