#include <iostream>
#include "QueueStack.h"
using namespace std;

int main() {
    QueueStack<int> s;
    int choice;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Check Empty\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            s.Push(value);
            cout << "Pushed: " << value << endl;
        } else if (choice == 2) {
            if (s.IsEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Popped: " << s.Pop() << endl;
            }
        } else if (choice == 3) {
            cout << (s.IsEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}