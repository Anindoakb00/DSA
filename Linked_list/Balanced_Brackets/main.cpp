#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string& str) {
    stack<char> st;
    for (char c : str) {
        if (c=='(' || c=='[' || c=='{') { st.push(c); }
        else if (c==')' || c==']' || c=='}') {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if (c==')' && top!='(') return false;
            if (c==']' && top!='[') return false;
            if (c=='}' && top!='{') return false;
        }
    }
    return st.empty();
}

int main() {
    cout << (isBalanced("{[()]}") ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced("{[(])}") ? "Balanced" : "Not Balanced") << endl;
    return 0;
}