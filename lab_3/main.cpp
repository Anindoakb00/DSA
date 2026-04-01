#include "dynarr.h"
#include <iostream>
using namespace std;
int main(){
    dynArr a;
    dynArr b(5);
    cout << "Enter the size of the array: ";
    for(int i =0; i<5; i++){
        int val;
        cin >> val;
        b.setValue(i,val);
       
    }
    cout << "Values in b: \n";
    for(int i = 0; i<5; i++){
        cout << b.getValue(i) <<" ";
        cout << endl;
    }

    //-task-2 lets allocate the values
    b.allocate(3);
    b.setValue(0,100);
    b.setValue(1,200);
    b.setValue(2,300);
    for(int i = 0; i<3; i++){
        cout <<  b.getValue(i) <<" ";
        cout << endl;
    }
    
  
    return 0;
    
}