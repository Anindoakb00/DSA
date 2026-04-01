#include "dynarr.h"
#include <iostream>
using namespace std;
dynArr::dynArr()
{
data = NULL;
size = 0;
}
dynArr::dynArr(int s)
{
data = new int[s];
size = s;
}
dynArr::~dynArr()
{
delete[] data;
}
int dynArr::getValue(int index)
{
return data[index];
}
void dynArr::setValue(int index, int value)
{
data[index] = value;
}
void dynArr::allocate(int s) {
    // Step 1: free the old array — MUST do this first
    delete[] data;

    // Step 2: allocate fresh array of new size
    data = new int[s];

    // Step 3: update size member variable
    size = s;
}