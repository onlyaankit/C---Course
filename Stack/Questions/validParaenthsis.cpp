#include <bits/stdc++.h>
#include<stack>
using namespace std;

bool validParathesis(const string& s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '{' || ch == '[' || ch == '(') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((top == '{' && ch != '}') || (top == '[' && ch != ']') || (top == '(' && ch != ')')) {
                return false;
            }
            st.pop();
        }
    }
    // If the stack is empty, all parentheses were matched
    return st.empty();
}

int main() {
    string s = "{()}[]";
    if (validParathesis(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }
    return 0;
}
