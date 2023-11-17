#pragma once
#include "Item.h"
class ItemNode {
    Item data;
    ItemNode* next;
public:
    ItemNode();
    void Set_ItemData(Item itm);
    Item get_ItemData();
    void Set_NextItem(ItemNode* node);
    ItemNode* get_NextItem();
};
