#include "ItemNode.h"
ItemNode::ItemNode() {}
void ItemNode::Set_ItemData(Item itm) {
    data = itm;

}
Item ItemNode::get_ItemData() {
    return data;
}
void ItemNode::Set_NextItem(ItemNode* node) {
    next = node;

}
ItemNode* ItemNode::get_NextItem() {
    return next;
}