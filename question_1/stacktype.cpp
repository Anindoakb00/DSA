#include "stacktype.h"
#include <stdexcept>
using namespace std;

template<class ItemType>
StackType<ItemType>::StackType() {
    maxStack = 50;
    top = -1;
    items = new ItemType[maxStack];
}

template<class ItemType>
StackType<ItemType>::StackType(int max) {
    maxStack = max;
    top = -1;
    items = new ItemType[maxStack];
}

template<class ItemType>
StackType<ItemType>::~StackType() {
    delete[] items;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() {
    return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() {
    return (top == maxStack - 1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem) {
    if (IsFull())
        throw std::runtime_error("Stack is full");
    top++;
    items[top] = newItem;
}

template<class ItemType>
ItemType StackType<ItemType>::Top() {
    if (IsEmpty())
        throw std::runtime_error("Stack is empty");
    return items[top];
}

template<class ItemType>
void StackType<ItemType>::Pop() {
    if (IsEmpty())
        throw std::runtime_error("Stack is empty");
    top--;
}

