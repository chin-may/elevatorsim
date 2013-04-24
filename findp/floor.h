#include "queue.h"
#include "Person.h"

#ifndef FLOOR_H
#define FLOOR_H

#define FLOOR_CAP 200

class floor{
    public:
    Queue* up;
    Queue* down;
    Person* members[FLOOR_CAP];
    int memnum;
    floor(int num);
    void print();
    int enter(Person* p);
};


#endif
