#include "Stack.h"
#include "tools.h"
bool Stack::IsEmpty() {
    if (top == NULL)
        return true;
    return false;
}
void Stack::createEmptyStack() {
    top = NULL;
}
void Stack::Push(Item itm) {
    ItemNode* temp = new ItemNode();
    temp->Set_ItemData(itm);
    temp->Set_NextItem(top);
    top = temp;

}
Item Stack::Pop() {
    ItemNode* temp = top;
    Item itm = temp->get_ItemData();
    top = top->get_NextItem();
    delete temp;
    return itm;
}
ItemNode* Stack::getTop() {
    return top;
}