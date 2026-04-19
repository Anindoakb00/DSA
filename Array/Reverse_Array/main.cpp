#include <iostream>
using namespace std;
int reverseorder(double arr[], int size){
    int start = 0; int end = size-1;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    int main(){
        int arr[] = {4,2,7,8,9,5};
        int sz = 7;
        reverseorder(arr,sz);
        for(int i=0; i<sz; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    }
}