#include "List.h"
#include "tools.h"
Node* List::getHead() {
    return this->head;
}
Node* List::getCurrent() {
    return this->current;
}
Node* List::getTail() {
    return this->tail;
}
void List::createEmptyList() {
    head = NULL;
    tail = NULL;

}
void List::promoteCurrent() {
    this->current = this->current->getNext();
}
void List::InitCurrent() {
    this->current = this->head;
}
void List::addToEnd(Node* new_node)
{
    if (head == NULL)
    {
        head = new_node;
        tail = head;
    }
    else
    {
        tail->SetNext(new_node);
        new_node->SetPrev(tail);
        tail = new_node;

    }
}