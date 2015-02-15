#ifndef _CLOCK_H
#define _CLOCK_H

#include "../Base/Types.h"

#include <chrono>

class Clock : Singleton< Clock > {

private:

	friend Singleton< Clock >;
	Clock() {
	}

public:

	TimeStamp getTime() {
		using namespace std::chrono;
		return duration_cast< nanoseconds >( high_resolution_clock::now().time_since_epoch() ).count();
	}
};

#endif
