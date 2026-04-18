#ifndef QUEUESTACK_H
#define QUEUESTACK_H
#include <queue>
using namespace std;

template <class T>
class QueueStack {
public:
    void Push(T val);
    T    Pop();
    bool IsEmpty() const;
private:
    queue<T> q1, q2;
};

#include "QueueStack.cpp"
#endif