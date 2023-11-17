#include "HelpFunctions.h"
#include "tools.h"
Node* partition(Node* left, Node* right)
{
    if (right == NULL)
        return right;
    if (left == NULL)
        return left;
    Node* pivot = left;
    int temp;
    while (left < right)
    {
        if (left->getData() > right->getData())
        {
            temp = left->getData();
            left->SetData(right->getData());
            right->SetData(temp);
            if (pivot == left)
            {
                pivot = right;
                left = left->getNext();
            }
            else
            {
                pivot = left;
                right = right->getPrev();

            }
        }
        else
        {
            if (pivot == left)
                right = right->getPrev();
            else
                left = left->getNext();
        }

    }
    return pivot;

}
void selection(Node* left, Node* right)
{
    Node* pivot;
    pivot = partition(left, right);
    if (pivot == NULL)
        return;
    if (right == left)
        return;
    if (pivot == left)
    {
        selection(pivot->getNext(), right);
    }
    else
    {
        selection(left, pivot->getPrev());
        selection(pivot->getNext(), right);
    }
}
bool IsNormal(int city, int n) {
    if (city >= 1 && city <= n)
        return true;
    return false;
}
void InitVariables(bool colorArr[], int n, List arr[])
{
    for (int i = 1; i <= n; i++)
    {
        arr[i].InitCurrent();
    }
    for (int i = 1; i <= n; i++)
    {
        colorArr[i] = true;
    }

}