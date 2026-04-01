#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

template<class ItemType>
class StackType {
public:
    StackType();
    StackType(int max);
    ~StackType();
    bool IsEmpty();
    bool IsFull();
    void Push(ItemType);
    ItemType Top();
    void Pop();
private:
    int top;
    int maxStack;
    ItemType* items;
};

#endif // STACKTYPE_H_INCLUDED
