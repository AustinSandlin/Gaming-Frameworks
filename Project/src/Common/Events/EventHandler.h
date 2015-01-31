#ifndef _EVENT_HANDLER_H
#define _EVENT_HANDLER_H

#include "Event.h"

class EventHandler {
public:
    // virtual ~EventHandler() = 0;
    virtual void HandleEvent( Event * event ) = 0;
};

#endif
