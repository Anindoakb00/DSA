#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(1); s.push(2); s.push(3);
    s.push(4); s.push(5);

    stack<int> temp;
    int count = 0;

    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
        count++;
    }
    // Restore original stack
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }

    cout << "Count: " << count << endl;
    return 0;
}