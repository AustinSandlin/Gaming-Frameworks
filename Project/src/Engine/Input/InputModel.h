#ifndef _INPUT_MODEL_H
#define _INPUT_MODEL_H

class InputModel {
public:
	static InputModel & GetInstance() {
		static InputModel singleton;
		return singleton;
	}
	void SetInputMap( InputMap * map );
	InputMap * GetInputMap();
private:
	InputModel() {}
	InputMap * map;
};

#endif
