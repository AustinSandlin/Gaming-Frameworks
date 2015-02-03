#ifndef _EVENT_HANDLER_H
#define _EVENT_HANDLER_H

#include "Event.h"

class EventHandler {
public:
<<<<<<< Updated upstream
    virtual ~EventHandler() {};
    virtual void HandleEvent( Event * event ) = 0;
=======
    virtual ~EventHandler();
    virtual void HandleEvent( Event & event ) = 0;
>>>>>>> Stashed changes
};

#endif
