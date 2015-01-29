#ifndef _CLOCK_MODEL_H
#define _CLOCK_MODEL_H

class ClockModel {
public:
	static ClockModel & GetInstance() {
		static ClockModel singleton;
		return singleton;
	}
private:
	ClockModel() {}
};

#endif
