#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType* next;
};

template <class ItemType>
class QueType {
public:
    QueType();                  // Constructor
    ~QueType();                 // Destructor
    void MakeEmpty();           // Empty the queue
    bool IsEmpty() const;       // Check if empty
    bool IsFull() const;        // Check if full
    void Enqueue(ItemType item);// Add item
    void Dequeue(ItemType& item);// Remove item

private:
    NodeType<ItemType>* front;
    NodeType<ItemType>* rear;
};
#endif // QUETYPE_H_INCLUDED
