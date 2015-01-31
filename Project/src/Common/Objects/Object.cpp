#include "Object.h"

Object::~Object() {
	// Iterate over the unordered map's values.
	// Commented because .enum_values() throws a 'no member' error.

	/*
	for ( auto * property : properties.enum_values() ) {
		// Release property from property table
	}
	*/
}

void Object::SetProperty( ObjectProperty* property ) {
	if ( property == NULL ) {
		// don't do this!
	}
	auto id = property->GetID();
	properties[ id ] = property;
}

void Object::ClearProperty( StringID id ) {
	auto it = properties.find( id );
	if ( it != properties.end() ) {

		properties.erase( it );
	}
}

ObjectProperty* Object::GetProperty( StringID id ) {
	auto it = properties.find( id );
	if ( it != properties.end() ) {
		
		properties.erase( it );
	}
	return properties.at( id );
}
