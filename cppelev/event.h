#ifndef EVENT_H
#define EVENT_H

using namespace std;

class event{
    //TODO What happens if I remove this virtual?
    virtual void happen(state *system) = 0;
};

#endif
