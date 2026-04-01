#include <iostream>
using namespace std;
#include "dynarr.h"
int main(){
    int r,c;
    cout << "Enter the number of rows and columns: ";
    cin >> r >> c;
    dynArr arr(r,c);
    for(int i =0; i<r; i++){
        for(int j =0; j<c; j++)
{
    int val;cin >> val;
    arr.setValue(i,j,val);
}    }

for(int i=0; i<r; i++){
  for(int j=0; j<c; j++)
    cout << arr.getValue(i,j) <<"";
    cout << endl;
}
return 0;
}