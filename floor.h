#include "queue.h"

#ifndef FLOOR_H
#define FLOOR_H

#define FLOOR_CAP 20

typedef struct floor_ floor;
struct floor_{
    Queue* up;
    Queue* down;
    Person* members[FLOOR_CAP];
    int memnum;
};

floor floor_new();

#endif
