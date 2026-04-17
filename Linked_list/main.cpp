#include <iostream>
// Including the .cpp file instead of .h is necessary for template classes 
// to prevent linker errors in standard compiler setups.
#include "linkedList.cpp" 

using namespace std;

// Helper function to print the list with spaces (for basic operations)
template <class T>
void PrintList(SortedType<T>& list) {
    int length = list.Length();
    list.Reset();
    T value;
    for (int i = 0; i < length; ++i) {
        list.GetNext(value);
        cout << value << " ";
    }
    cout << endl;
}

// Helper function to print the list in set notation (for Task 1 & Task 2)
template <class T>
void PrintSet(SortedType<T>& list, const string& prefix) {
    int length = list.Length();
    list.Reset();
    T value;
    cout << prefix << "{";
    for (int i = 0; i < length; ++i) {
        list.GetNext(value);
        cout << value;
        if (i < length - 1) cout << ",";
    }
    cout << "}" << endl;
}

int main() {
    // ==========================================
    // Basic Operations
    // ==========================================
    cout << "--- Basic Operations ---" << endl;

    // Create a list of integers
    SortedType<int> list;

    // Insert four items: 5 4 2 1
    list.Insert(5);
    list.Insert(4);
    list.Insert(2);
    list.Insert(1);

    // Print the list
    PrintList(list);

    // Insert one item: 7
    list.Insert(7);

    // Print the list
    PrintList(list);

    // Search 6 and print whether found or not
    bool found;
    list.Search(6, found);
    if (found) cout << "Item is found" << endl;
    else cout << "Item is not found" << endl;

    // Search 5 and print whether found or not
    list.Search(5, found);
    if (found) cout << "Item is found" << endl;
    else cout << "Item is not found" << endl;

    // Delete 1
    list.Delete(1);

    // Print the list
    PrintList(list);

    // Delete 4
    list.Delete(4);

    // Print the list
    PrintList(list);

    // Delete 16 (Will trigger the internal cout error)
    list.Delete(16);

    cout << endl;


    // ==========================================
    // Task 1: Union of two sorted lists
    // ==========================================
    cout << "--- Task 1: Union ---" << endl;
    
    // Initialize List T
    SortedType<int> T;
    T.Insert(1); T.Insert(2); T.Insert(5); 
    T.Insert(6); T.Insert(10); T.Insert(14);

    // Initialize List F
    SortedType<int> F;
    F.Insert(3); F.Insert(2); F.Insert(4); 
    F.Insert(6); F.Insert(9); F.Insert(16); F.Insert(19);

    SortedType<int> unionList;
    int val;

    // Add unique elements of T to unionList
    T.Reset();
    for(int i = 0; i < T.Length(); i++) {
        T.GetNext(val);
        unionList.Search(val, found);
        if(!found) unionList.Insert(val);
    }

    // Add unique elements of F to unionList
    F.Reset();
    for(int i = 0; i < F.Length(); i++) {
        F.GetNext(val);
        unionList.Search(val, found);
        if(!found) unionList.Insert(val);
    }

    // Output Expected: T U F = {1,2,3,4,5,6,9,10,14,16,19}
    PrintSet(unionList, "T U F = ");
    
    cout << endl;


    // ==========================================
    // Task 2: Intersection of two sorted lists
    // ==========================================
    cout << "--- Task 2: Intersection ---" << endl;
    
    SortedType<int> intersectionList;

    // Iterate through T, and if the element is found in F, add to intersection
    T.Reset();
    for(int i = 0; i < T.Length(); i++) {
        T.GetNext(val);
        F.Search(val, found);
        
        if(found) {
            // Check if it's already in the intersection list to prevent duplicates
            bool alreadyAdded;
            intersectionList.Search(val, alreadyAdded);
            if(!alreadyAdded) {
                intersectionList.Insert(val);
            }
        }
    }

    // Output Expected: T ∩ F = {2,6}
    // Note: Using "n" instead of the intersection symbol for better console compatibility
    PrintSet(intersectionList, "T n F = ");

    return 0;
}
