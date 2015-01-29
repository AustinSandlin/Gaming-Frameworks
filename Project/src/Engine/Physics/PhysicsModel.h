#ifndef _PHYSICS_MODEL_H
#define _PHYSICS_MODEL_H

class PhysicsModel {
public:
	static PhysicsModel & GetInstance() {
		static PhysicsModel singleton;
		return singleton;
	}
private:
	PhysicsModel() {}
};

#endif
