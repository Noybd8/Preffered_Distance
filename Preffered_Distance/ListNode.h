#pragma once
#include "Node.h"
class List {
    Node* head;
    Node* current;
    Node* tail;

public:
    Node* getHead();
    Node* getCurrent();
    Node* getTail();
    void promoteCurrent();
    void InitCurrent();
    void createEmptyList();
    void addToEnd(Node* new_node);
};
