#ifndef _CLOCK_H
#define _CLOCK_H

#include "../Base/Singleton.h"
#include "../Base/Types.h"

#include <chrono>

class Clock : public Singleton< Clock > {

private:

	friend class Singleton< Clock >;
	Clock() {
	}

public:

	TimeStamp getTime() {
		using namespace std::chrono;
		return duration_cast< nanoseconds >( high_resolution_clock::now().time_since_epoch() ).count();
	}
};

#endif
