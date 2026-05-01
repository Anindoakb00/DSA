#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <typename T>
struct BSTNode {
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    
    BSTNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    BSTNode<T>* root;
    BSTNode<T>* InsertHelper(BSTNode<T>* node, T value);
    void PreOrderHelper(BSTNode<T>* node);
    void InOrderHelper(BSTNode<T>* node);
    void PostOrderHelper(BSTNode<T>* node);
    T SumHelper(BSTNode<T>* node);
    
public:
    BST();
    ~BST();
    void Insert(T value);
    void PrintPreOrder();
    void PrintInOrder();
    void PrintPostOrder();
    T GetSum();
};

#endif
