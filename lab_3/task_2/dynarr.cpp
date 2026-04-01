#include "dynarr.h"
#include <iostream>
using namespace std;
dynArr::dynArr(int r, int c)
{
rows = r;
cols = c;
data = new int*[rows];
for(int i = 0; i<rows;i++){
    data[i] = new int[cols];
}
}

dynArr::~dynArr(){
    for(int i =0;i<rows;i++){
        delete[] data[i];
    }
    delete[] data;
}
void dynArr::setValue(int row, int col, int value){
    data[row][col] = value;

}
int dynArr::getValue(int row, int col)
{
return data[row][col];
}
