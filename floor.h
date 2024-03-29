#include "queue.h"
#include "Person.h"

#ifndef FLOOR_H
#define FLOOR_H

#define FLOOR_CAP 200

typedef struct floor_ floor;
struct floor_{
    Queue* up;
    Queue* down;
    Person* members[FLOOR_CAP];
    int memnum;
};

floor* floor_new();
void floor_print();
int floor_enter(floor* f, Person* p);

#endif
