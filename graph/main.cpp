#include <iostream>
#include<algorithm>
#include "header.cpp"
using namespace std;

// Function to build a balanced BST from sorted array
template <class ItemType>
void BuildBalancedBST(TreeType<ItemType>& tree, ItemType arr[], int start, int end) {
    if (start > end) return;
    int mid = (start + end) / 2;
    tree.InsertItem(arr[mid]);
    BuildBalancedBST(tree, arr, start, mid - 1);   // left subtree
    BuildBalancedBST(tree, arr, mid + 1, end);     // right subtree
}

int main() {
    TreeType<int> tree;
    bool found;

    // 1. Create a tree object (already done above)

    // 2. Print if tree is empty
    cout << (tree.IsEmpty() ? "Tree is empty" : "Tree is not empty") << endl;

    // 3. Insert ten items
    int items[] = {4, 9, 2, 7, 3, 11, 17, 0, 5, 1};
    for (int x : items) {
        tree.InsertItem(x);
    }

    // 4. Print if tree is empty
    cout << (tree.IsEmpty() ? "Tree is empty" : "Tree is not empty") << endl;

    // 5. Print length of tree
    cout << "Length of tree: " << tree.LengthIs() << endl;

    // 6. Retrieve 9
    int item = 9;
    tree.RetrieveItem(item, found);
    cout << (found ? "Item is found" : "Item is not found") << endl;

    // 7. Retrieve 13
    item = 13;
    tree.RetrieveItem(item, found);
    cout << (found ? "Item is found" : "Item is not found") << endl;

    // 8. Print elements in InOrder
    cout << "InOrder: ";
    tree.ResetTree(IN_ORDER);
    bool finished = false;
    while (!finished) {
        tree.GetNextItem(item, IN_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    // 9. Print elements in PreOrder
    cout << "PreOrder: ";
    tree.ResetTree(PRE_ORDER);
    finished = false;
    while (!finished) {
        tree.GetNextItem(item, PRE_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    // 10. Print elements in PostOrder
    cout << "PostOrder: ";
    tree.ResetTree(POST_ORDER);
    finished = false;
    while (!finished) {
        tree.GetNextItem(item, POST_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    // 11. Make tree empty
    tree.MakeEmpty();
    cout << (tree.IsEmpty() ? "Tree is empty" : "Tree is not empty") << endl;

    // 12. Build BST with minimum height
    int seq[] = {11, 9, 4, 2, 7, 3, 17, 0, 5, 1};
    int n = sizeof(seq) / sizeof(seq[0]);

    // Sort sequence (like inorder)
    sort(seq, seq + n);

    TreeType<int> balancedTree;
    BuildBalancedBST(balancedTree, seq, 0, n - 1);

    cout << "Balanced BST (InOrder): ";
    balancedTree.ResetTree(IN_ORDER);
    finished = false;
    while (!finished) {
        balancedTree.GetNextItem(item, IN_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
