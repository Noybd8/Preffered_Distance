#pragma once
class Node {
    int data;
    Node* next;
    Node* prev;

public:
    Node(int item);
    ~Node();
    Node* getNext();
    int getData();
    Node* getPrev();
    void SetData(int x);
    void SetPrev(Node* pre);
    void SetNext(Node* nxt);

};
