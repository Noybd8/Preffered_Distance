#include "Node.h"
#include "tools.h"
Node::Node(int item) {
    this->data = item;
    this->next = NULL;
}
void Node::SetNext(Node* nxt) {
    this->next = nxt;
}
int Node::getData() {
    return this->data;
}
void Node::SetData(int x) {
    this->data = x;
}
void Node::SetPrev(Node* pre) {
    this->prev = pre;
}
Node* Node::getNext() {
    return this->next;
}
Node* Node::getPrev() {
    return this->prev;
}