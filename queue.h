/*
 * Author: Chinmay Bapat(CS10B059)
 * Queue data structure
 */
#include "Person.h"

#ifndef QUEUE_H
#define QUEUE_H

// Node for the link list
typedef struct Node_ Node;
struct Node_ {
    Person* data;
    Node* next;
};

typedef struct Queue_ Queue;
struct Queue_ {
    Node* head;
    Node* tail;
    int length;
};

// Create a new node with data and next element (can be NULL)
Node* node_new( Person* data, Node* next );

Queue* queue_new();

void queue_enque(Queue* q, Person* data);

Person* queue_deque(Queue* q);

#endif //QUEUE_H
