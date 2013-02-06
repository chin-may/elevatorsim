#ifndef ELEVATOR_H

#define ELEVATOR_CAP 8
#define ELEVATOR_H

typedef struct elevator_ elevator;
struct elevator_{
    Person* passengers[ELEVATOR_CAP];
    int pnum;
}
#endif
