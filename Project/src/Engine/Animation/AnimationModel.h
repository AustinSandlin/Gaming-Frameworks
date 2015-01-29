#ifndef _ANIMATION_MODEL_H
#define _ANIMATION_MODEL_H

class AnimationModel {
public:
	static AnimationModel & GetInstance() {
		static AnimationModel singleton;
		return singleton;
	}
private:
	AnimationModel() {}
};

#endif