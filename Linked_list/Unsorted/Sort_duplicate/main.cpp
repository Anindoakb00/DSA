#include <iostream>
#include "unsortedtype.cpp"

using namespace std;

void PrintList(UnsortedType<int>& list)
{
    int n = list.Length();
    list.Reset();

    for (int i = 0; i < n; i++)
    {
        int v;
        list.GetNext(v);
        cout << v << " ";
    }
    cout << endl;
}

int sort(UnsortedType<int>& list)
{
    int n = list.Length();
    if (n <= 1)
    {
        return n;
    }

    int* arr = new int[n];

    // 1. Snapshot list into array.
    list.Reset();
    for (int i = 0; i < n; i++)
    {
        list.GetNext(arr[i]);
    }

    // 2. Bubble sort array in ascending order.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 3. Rebuild list and skip duplicates.
    // Insert largest first so final head is smallest.
    list.MakeEmpty();
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && arr[i] == arr[i + 1])
        {
            continue;
        }
        list.Insert(arr[i]);
    }

    delete[] arr;
    return list.Length();
}

int main()
{
    UnsortedType<int> list;

    list.Insert(20);
    list.Insert(10);
    list.Insert(20);
    list.Insert(5);
    list.Insert(10);
    list.Insert(30);

    cout << "Before sort + deduplicate: ";
    PrintList(list);

    int newSize = sort(list);

    cout << "After sort + deduplicate:  ";
    PrintList(list);
    cout << "New size: " << newSize << endl;

    return 0;
}
