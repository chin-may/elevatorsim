#include <stdlib.h>
#include "Person.h"

Person* person_new(int id){
    Person* ret = malloc(sizeof(Person));
    ret->id = id;
    return ret;
}
