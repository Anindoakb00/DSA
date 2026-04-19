#include <iostream>
#include "unsortedtype.cpp"

using namespace std;
void printList(UnsortedType<int>& list){
    int ln;
    list.Reset();
    ln = list.Length();
    for( int i=0; i<ln; i++){
           int value;
           list.GetNext(value);
           cout << value << " ";
    }
    cout << endl;

}
int main(){
    UnsortedType<int> L1;
    UnsortedType<int> L2;
    UnsortedType<int> merged;
    L1.Insert(20);
    L1.Insert(300);
    L1.Insert(40);

    L2.Insert(40);
    L2.Insert(50);
    L2.Insert(60);

    L1.Reset();
    for(int i=0;i<L1.Length(); i++){
        int v;
        L1.GetNext(v);
        merged.Insert(v);

    }

    L2.Reset();
    for(int i=0;i<L2.Length(); i++){
        int v;
        L2.GetNext(v);
        merged.Insert(v);
    }
    cout<< "L1: ";
    printList(L1);
    cout<< "L2: ";
    printList(L2);
    cout<< "Merged: ";
    printList(merged);

}