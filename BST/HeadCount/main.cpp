#include "BST.h"

int main() {
    BST<int> tree;
    
    for (int v : {50, 30, 20, 40, 70, 60, 80}) {
        tree.Insert(v);
    }
    
    cout << "Pre-order: ";
    tree.PrintPreOrder();
    
    cout << "In-order: ";
    tree.PrintInOrder();
    
    cout << "Post-order: ";
    tree.PrintPostOrder();
    
    cout << "Height (edge count): " << tree.GetHeight() << endl;
    
    return 0;
}
