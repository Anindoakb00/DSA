#include "QueueStack.h"

template <class T>
void QueueStack<T>::Push(T val) {
    q2.push(val);
    while (!q1.empty()) {       // drain q1 into q2
        q2.push(q1.front()); q1.pop();
    }
    swap(q1, q2);               // q1 now has LIFO order
}

template <class T>
T QueueStack<T>::Pop() {
    T val = q1.front();
    q1.pop();
    return val;
}

template <class T>
bool QueueStack<T>::IsEmpty() const { return q1.empty(); }