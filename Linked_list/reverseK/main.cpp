#include <iostream>
#include <queue>
#include <stack>
using namespace std;



// Reverse only the first k elements of queue q.
void reverseFirstK(queue<int>& q, int k) {
    int n = q.size();                    // Current queue size.
    if (k <= 0 || k > n) return;         // Ignore invalid k values.
    const int toReverse = k;             // Save original k before decrementing.

    stack<int> s;                        // Temporary stack for reversal.
    while (k--) {                        // Move first k queue elements into stack.
        s.push(q.front());               // Store current front.
        q.pop();                         // Remove it from queue.
    }

    while (!s.empty()) {                 // Push back from stack to queue (reversed order).
        q.push(s.top());                 // Take top element from stack.
        s.pop();                         // Remove pushed element from stack.
    }

    for (int rotate = n - toReverse; rotate > 0; --rotate) { // Keep untouched part in original order.
        q.push(q.front());               // Move front to back.
        q.pop();                         // Remove original front.
    }

}
int main(){
    queue<int> q;                        // Input queue.
    cout<<"Enter the number of elements in the queue:"<< endl;
    int n; cin >>n;                      // Number of queue elements.
    cout << "Enter the elements of the queue:"<< endl;
    while (n--) {                        // Read exactly n elements.
        int x;
        cin >> x;                        // Input one value.
        q.push(x);                       // Add value to queue.
    }
    int k;
    cout << "Enter k (how many elements to reverse from the front):" << endl;
    cin >> k;                            // Dynamic k from user.

    reverseFirstK(q, k);                 // Reverse first k elements.
    while (!q.empty()) {                 // Print final queue.
        cout << q.front() << " ";       // Output current front.
        q.pop();                         // Remove printed element.
    }
    return 0;                            // Program finished successfully.
}
