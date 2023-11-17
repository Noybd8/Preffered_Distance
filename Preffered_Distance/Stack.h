#pragma once
#include "ItemNode.h"
class Stack {
    ItemNode* top;

public:
    bool IsEmpty();
    ItemNode* getTop();
    void createEmptyStack();
    void Push(Item itm);
    Item Pop();
};
