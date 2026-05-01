#include "BST.h"

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

template <typename T>
BST<T>::~BST() {
}

template <typename T>
BSTNode<T>* BST<T>::InsertHelper(BSTNode<T>* node, T value) {
    if (node == nullptr) {
        return new BSTNode<T>(value);
    }
    
    if (value < node->data) {
        node->left = InsertHelper(node->left, value);
    } else {
        node->right = InsertHelper(node->right, value);
    }
    
    return node;
}

template <typename T>
void BST<T>::Insert(T value) {
    root = InsertHelper(root, value);
}

template <typename T>
void BST<T>::PreOrderHelper(BSTNode<T>* node) {
    if (!node) return;
    cout << node->data << " ";
    PreOrderHelper(node->left);
    PreOrderHelper(node->right);
}

template <typename T>
void BST<T>::PrintPreOrder() {
    PreOrderHelper(root);
    cout << endl;
}

template <typename T>
void BST<T>::InOrderHelper(BSTNode<T>* node) {
    if (!node) return;
    InOrderHelper(node->left);
    cout << node->data << " ";
    InOrderHelper(node->right);
}

template <typename T>
void BST<T>::PrintInOrder() {
    InOrderHelper(root);
    cout << endl;
}

template <typename T>
void BST<T>::PostOrderHelper(BSTNode<T>* node) {
    if (!node) return;
    PostOrderHelper(node->left);
    PostOrderHelper(node->right);
    cout << node->data << " ";
}

template <typename T>
void BST<T>::PrintPostOrder() {
    PostOrderHelper(root);
    cout << endl;
}

template <typename T>
T BST<T>::SumHelper(BSTNode<T>* node) {
    if (!node) return 0;
    return node->data + SumHelper(node->left) + SumHelper(node->right);
}

template <typename T>
T BST<T>::GetSum() {
    return SumHelper(root);
}

template class BST<int>;
