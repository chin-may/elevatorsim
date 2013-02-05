#ifndef PERSON_H
#define PERSON_H

typedef struct Person_ Person;

struct Person_{
    int id;
};

Person* person_new(int id);

#endif //PERSON_H
