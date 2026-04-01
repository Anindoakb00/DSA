#include "quetype.h"


template <class ItemType>
QueType<ItemType>::QueType() {
    front = NULL;
    rear = NULL;
}

template <class ItemType>
QueType<ItemType>::~QueType() {
    MakeEmpty();
}

template <class ItemType>
void QueType<ItemType>::MakeEmpty() {
    NodeType<ItemType>* tempPtr;
    while (front != NULL) {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const {
    return (front == NULL);
}

template <class ItemType>
bool QueType<ItemType>::IsFull() const {
    try {
        NodeType<ItemType>* location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (bad_alloc& exception) {
        return true;
    }
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType item) {
    if (IsFull())
        throw overflow_error("Queue is full");

    NodeType<ItemType>* newNode = new NodeType<ItemType>;
    newNode->info = item;
    newNode->next = NULL;

    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item) {
    if (IsEmpty())
        throw underflow_error("Queue is empty");

    NodeType<ItemType>* tempPtr = front;
    item = front->info;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete tempPtr;
}
