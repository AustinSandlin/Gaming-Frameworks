#ifndef _CLOCK_H
#define _CLOCK_H

#include "../Base/Singleton.h"
#include "../Base/Types.h"

#include <chrono>

class Clock:

	public Singleton< Clock > {

private:

	const TimeStamp DEFAULT_FRAME_SIZE = 16666667; // Nanoseconds ( 60 Hz )

	TimeStamp frame;
	TimeStamp frameSize;

	friend class Singleton< Clock >;

	Clock() {
		setFrame();
		setFrameSize( DEFAULT_FRAME_SIZE );
	}

public:

	TimeStamp getTime() const {
		using namespace std::chrono;
		return duration_cast< nanoseconds >( high_resolution_clock::now().time_since_epoch() ).count();
	}
	TimeStamp getCurrentFrame() const {
		return frame;
	}
	TimeStamp getNextFrame() const {
		return frame + frameSize;
	}
	void setFrame() {
		frame = getTime();
	}
	void setFrameSize( TimeStamp size ) {
		frameSize = size;
	}
};

#endif
