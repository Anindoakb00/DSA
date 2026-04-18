
#include <iostream>             
using namespace std;
void findMinMax(double arr[], int size, double &minValue, double &maxValue) {
    minValue = arr[0];
    maxValue = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be greater than 0." << endl;
        return 0;
    }

    double arr[n];

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double minValue, maxValue;
    findMinMax(arr, n, minValue, maxValue);

    cout << "Minimum value: " << minValue << endl;
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}