#include <iostream>
using namespace std;

class CircularQueue{
  int* arr;
  int currSize, cap;
  int f,r;
  public:
  CircularQueue(int size){
    cap = size;
    arr = new int[cap];
    f=0;
    r=-1;
  }
  void push(){
if(currSize ==cap){
  cout<<"CQ IS FULL\n";
  return;
}
r=(r+1)%cap;
arr[r] = data;
currSize++;
  }
  void pop(){

  }
  int front(){

  }
  bool empty(){
    return currSize ==0;
  }
};

int main(){
  return 0;
}
