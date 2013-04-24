#ifndef NEW_ENTRY_EVENT_H
#define NEW_ENTRY_EVENT_H

#include "event.h"
#include "consts.h"
class new_entry_event: public event{
    public:
        void happen(state *st_, std::list<event*> *events);
};

#endif
