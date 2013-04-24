#ifndef EVENT_H
#define EVENT_H
#include "state.h"
#include <list>
class event{
    public:
    //TODO What happens if I remove this virtual?
    virtual void happen(state *system, std::list<event*> *events) = 0;
};

#endif
