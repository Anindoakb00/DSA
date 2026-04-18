#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n = 5;
    queue<string> bfsQ;
    stack<string> s;
    bfsQ.push("1");

    for (int i = 0; i < n; i++) {
        string f = bfsQ.front(); bfsQ.pop();
        s.push(f);              // push to stack = will reverse order
        bfsQ.push(f + "0");
        bfsQ.push(f + "1");
    }

    bool first = true;
    while (!s.empty()) {
        if (!first) cout << ", ";
        cout << s.top(); s.pop();
        first = false;
    }
    cout << endl;
    return 0;
}