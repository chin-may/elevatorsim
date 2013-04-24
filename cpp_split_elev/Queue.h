/*
 * Author: Chinmay Bapat(CS10B059)
 * Queue data structure
 */
#include "Person.h"

#ifndef QUEUE_H
#define QUEUE_H

// Node for the link list
class Node {
    public:
    Person* data;
    Node* next;
    // Create a new node with data and next element (can be NULL)
    Node( Person* data, Node* next );
};

class Queue {
    public:
    Node* head;
    Node* tail;
    int length;
    Queue();
    void enque(Person* data);
    Person* deque();
};




#endif //QUEUE_H
