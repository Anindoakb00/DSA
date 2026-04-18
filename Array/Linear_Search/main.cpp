#include <iostream>
using namespace std;


int lenearSearch(double arr[],int size, int target){
    for(int i=0;i<size;i++){
        if(arr[i]== target) return i;
        
    }
    return -1;
}
int main(){
    int s;
    if(s==0) return 0;
    cout<<"Enter the size of array " << endl;cin>> s;
    
    double array[s];
    cout<<"Enter the elements of array"<<"\n"<< endl;
    for(int i =0; i<s;i++){
       cin>>array[i];
    }
    double t;
    cout<<"Enter the targeted value: " << endl;cin>> t;
    int result = lenearSearch(array, s, t);
    if(result != -1){
        cout << "Desired position is: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
  
    


}