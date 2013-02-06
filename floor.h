#include "Queue.h"

#ifndef FLOOR_H
#define FLOOR_H

typedef struct floor_ floor;
struct floor_{
    Queue* up;
    Queue* down;
};

floor floor_new();
