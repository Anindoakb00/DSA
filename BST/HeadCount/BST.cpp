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
int BST<T>::HeightHelper(BSTNode<T>* node) {
    if (!node) return -1;
    int leftHeight = HeightHelper(node->left);
    int rightHeight = HeightHelper(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

template <typename T>
int BST<T>::GetHeight() {
    return HeightHelper(root);
}

template class BST<int>;
