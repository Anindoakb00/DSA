#include "BST.h"

int main() {
    BST<int> tree;
    
    for (int v : {50, 30, 20, 40, 70, 60, 80}) {
        tree.Insert(v);
    }
    
    cout << "Original Tree:\n";
    cout << "Pre-order: ";
    tree.PrintPreOrder();
    
    cout << "In-order: ";
    tree.PrintInOrder();
    
    cout << "Post-order: ";
    tree.PrintPostOrder();
    
    tree.Mirror();
    
    cout << "\nMirror Tree:\n";
    cout << "Pre-order: ";
    tree.PrintPreOrder();
    
    cout << "In-order: ";
    tree.PrintInOrder();
    
    cout << "Post-order: ";
    tree.PrintPostOrder();
    
    return 0;
}
